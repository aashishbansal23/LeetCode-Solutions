class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if((r!=entrance[0] || c!=entrance[1]) && (r==0 || c==0 || r==m-1 || c==n-1)){
                    return ans;
                }
                if(r-1>=0 && maze[r-1][c]=='.' && !visited[r-1][c]){
                    q.push({r-1, c});
                    visited[r-1][c] = true;
                }
                if(r+1<m && maze[r+1][c]=='.' && !visited[r+1][c]){
                    q.push({r+1, c});
                    visited[r+1][c] = true;
                }
                if(c-1>=0 && maze[r][c-1]=='.' && !visited[r][c-1]){
                    q.push({r, c-1});
                    visited[r][c-1] = true;
                }
                if(c+1<n && maze[r][c+1]=='.' && !visited[r][c+1]){
                    q.push({r, c+1});
                    visited[r][c+1] = true;
                }
                size--;
            }
            ans++;
        }
        return -1;
    }
};