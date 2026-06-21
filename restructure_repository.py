"""
Restructures LeetCode-Solutions into the spec:

    0001-1000/
        0011_container_with_most_water/
            README.md
            0011_container_with_most_water.cpp
    1001-2000/
        ...

Each problem gets its own git commit: "Added LeetCode <number> solution"

BEFORE RUNNING:
- Run inside a fresh local clone of your repo (not your only copy!)
- Leave DRY_RUN = True first to preview the plan -- no changes, no commits
- Once you've reviewed it, set DRY_RUN = False and re-run
- This script does NOT push. Run `git push` yourself once, at the end,
  after reviewing the commit history.
"""

import os
import re
import subprocess

ROOT = "."
RANGE_SIZE = 1000
DRY_RUN = False

# Recognized solution file extensions -- used to pick the right file
# out of a problem folder if there's more than just README.md inside.
SOLUTION_EXTENSIONS = {
    ".cpp", ".c", ".py", ".java", ".js", ".ts", ".go", ".rb", ".cs", ".swift", ".sql"
}


def get_range_folder(num):
    start = ((num - 1) // RANGE_SIZE) * RANGE_SIZE + 1
    end = start + RANGE_SIZE - 1
    return f"{start:04d}-{end}"


def run(cmd):
    print("  $", " ".join(cmd))
    if not DRY_RUN:
        subprocess.run(cmd, check=True)


def restructure_repository_leetcode():
    entries = sorted(
        d for d in os.listdir(ROOT)
        if os.path.isdir(os.path.join(ROOT, d)) and re.match(r"^\d+-", d)
    )

    done, skipped = 0, 0

    for folder in entries:
        m = re.match(r"^(\d+)-(.+)$", folder)
        if not m:
            continue
        num = int(m.group(1))
        slug = m.group(2)
        range_folder = get_range_folder(num)
        new_name = f"{num:04d}_{slug.replace('-', '_')}"
        new_dir = os.path.join(range_folder, new_name)

        files = os.listdir(folder)
        readme = next((f for f in files if f.lower() == "readme.md"), None)
        sol = next(
            (f for f in files if os.path.splitext(f)[1].lower() in SOLUTION_EXTENSIONS),
            None,
        )
        
        remaining = [f for f in files if f not in (readme, sol)]
        unexpected = [f for f in remaining if f.lower() != "notes.md"]
        if unexpected:
            print(f"  SKIP (unexpected extra file(s) {unexpected} in {folder} -- left in place, check it manually.)")
            print("  Remaining files:", os.listdir(folder))
            skipped += 1
            continue

        print(f"\nProblem {num}: {folder} -> {new_dir}")

        if not DRY_RUN:
            os.makedirs(new_dir, exist_ok=True)

        if readme:
            run(["git", "mv", os.path.join(folder, readme), os.path.join(new_dir, "README.md")])
        else:
            print(f"  NOTE: no README.md found in {folder}; problem statement won't carry over.")
        
        if sol:
            ext = os.path.splitext(sol)[1]
            new_sol_name = f"{new_name}{ext}"
            run(["git", "mv", os.path.join(folder, sol), os.path.join(new_dir, new_sol_name)])
        else:
            print(f"  NOTE: no solution file found in {folder}; solution won't carry over.")

        # NOTES.md (if present) is discarded -- anything else would have
        # caused this problem to be skipped above instead.
        for extra in remaining:
            run(["git", "rm", os.path.join(folder, extra)])

        if not DRY_RUN:
            if os.path.exists(folder):
                try:
                    os.rmdir(folder)
                except OSError:
                    print(f"  WARNING: {folder} not empty after move -- left in place, check it manually.")
                    if os.path.exists(folder):
                        print("  Remaining files:", os.listdir(folder))

        run(["git", "add", new_dir])
        run(["git", "commit", "-m", f"Added LeetCode {num} solution"])

        done += 1

    print(f"\n{'[DRY RUN] ' if DRY_RUN else ''}Done. {done} problems processed, {skipped} skipped.")
    if DRY_RUN:
        print("No files were changed and no commits were made. Set DRY_RUN = False to actually run it.")
    else:
        print("All commits are LOCAL. Review with `git log --oneline`, then run `git push` once yourself.")
    
def restructure_repository_gfg():
    entries = sorted(
        d for d in os.listdir(ROOT)
        if os.path.isdir(os.path.join(ROOT, d)) and re.match(r"^.+\s-\sGFG$", d)
    )

    done, skipped = 0, 0

    for folder in entries:
        slug = re.sub(r"\s-\sGFG$", "", folder)

        new_name = re.sub(r"[^a-zA-Z0-9]+", "_", slug).strip("_").lower()
        new_dir = os.path.join("GFG", new_name)

        files = os.listdir(folder)
        readme = next((f for f in files if f.lower() == "readme.md"), None)
        sol = next(
            (f for f in files if os.path.splitext(f)[1].lower() in SOLUTION_EXTENSIONS),
            None,
        )

        remaining = [f for f in files if f not in (readme, sol)]
        unexpected = [f for f in remaining if f.lower() != "notes.md"]
        if unexpected:
            print(f"  SKIP (unexpected extra file(s) {unexpected} in {folder} -- left in place, check it manually.)")
            print("  Remaining files:", os.listdir(folder))
            skipped += 1
            continue

        print(f"\nProblem: {folder} -> {new_dir}")

        if not DRY_RUN:
            os.makedirs(new_dir, exist_ok=True)

        if readme:
            run(["git", "mv", os.path.join(folder, readme), os.path.join(new_dir, "README.md")])
        else:
            print(f"  NOTE: no README.md found in {folder}; problem statement won't carry over.")

        if sol:
            ext = os.path.splitext(sol)[1]
            new_sol_name = f"{new_name}{ext}"
            run(["git", "mv", os.path.join(folder, sol), os.path.join(new_dir, new_sol_name)])
        else:
            print(f"  NOTE: no solution file found in {folder}; solution won't carry over.")


        # NOTES.md (if present) is discarded -- anything else would have
        # caused this problem to be skipped above instead.
        for extra in remaining:
            run(["git", "rm", os.path.join(folder, extra)])

        if not DRY_RUN:
            if os.path.exists(folder):
                try:
                    os.rmdir(folder)
                except OSError:
                    print(f"  WARNING: {folder} not empty after move -- left in place, check it manually.")
                    if os.path.exists(folder):
                        print("  Remaining files:", os.listdir(folder))
        
        run(["git", "add", new_dir])
        run(["git", "commit", "-m", f"Added GFG {slug} solution"])

        done += 1

    print(f"\n{'[DRY RUN] ' if DRY_RUN else ''}Done. {done} GFG problems processed, {skipped} skipped.")


if __name__ == "__main__":
    restructure_repository_leetcode()
    restructure_repository_gfg()
