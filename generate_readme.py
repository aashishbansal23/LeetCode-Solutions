import os
import re

ROOT = "."
RANGES = ["0001-1000", "1001-2000", "2001-3000", "3001-4000"]


def parse_problem_folder(folder_name):
    """
    Extract number + title from folder like:
    123_two_sum
    """
    match = re.match(r"(\d+)_(.*)", folder_name)
    if match:
        number = int(match.group(1))
        title = match.group(2).replace("_", " ").title()
        return number, title
    return None, None


def find_solution_file(problem_path):
    """
    Find first non-readme file as solution
    """
    for f in sorted(os.listdir(problem_path)):
        if f.lower() == "readme.md":
            continue
        if os.path.isfile(os.path.join(problem_path, f)):
            return f
    return None


def generate_table(range_folder):
    range_path = os.path.join(ROOT, range_folder)

    if not os.path.exists(range_path):
        return f"*(No problems added yet in {range_folder})*"

    rows = [
        "| # | Title | Solution |",
        "|---|-------|----------|",
    ]

    # iterate problem folders
    for problem_folder in sorted(os.listdir(range_path)):
        problem_path = os.path.join(range_path, problem_folder)

        if not os.path.isdir(problem_path):
            continue

        num, title = parse_problem_folder(problem_folder)

        if num is None:
            continue

        sol_file = find_solution_file(problem_path)

        if sol_file:
            ext = sol_file.split(".")[-1].upper()
            sol_link = f"[{ext}]({range_folder}/{problem_folder}/{sol_file})"
        else:
            sol_link = "-"

        rows.append(
            f"| {num} | {title} | {sol_link} |"
        )

    return "\n".join(rows)


def main():
    readme_lines = [
        "# LeetCode Solutions (Number-wise)\n",
        "This repository contains my solutions organized **by problem number ranges**.\n",
        "---\n",
        "## 📂 Quick Navigation",
    ]

    for folder in RANGES:
        readme_lines.append(f"- [{folder}](#{folder})")

    readme_lines.append("\n---\n")

    for folder in RANGES:
        readme_lines.append(f"## {folder}\n")
        readme_lines.append(generate_table(folder))
        readme_lines.append("\n[🔼 Back to Top](#leetcode-solutions-number-wise)\n")
        readme_lines.append("---\n")

    with open("README.md", "w", encoding="utf-8") as f:
        f.write("\n".join(readme_lines))

    print("README.md updated successfully!")


if __name__ == "__main__":
    main()