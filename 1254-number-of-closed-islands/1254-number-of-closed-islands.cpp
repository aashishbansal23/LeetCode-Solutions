class Solution {
    void makeOne(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n){
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            grid[r][c] = 1;
            if(r-1>=0 && grid[r-1][c]==0 && !visited[r-1][c]){
                q.push({r-1, c});
                visited[r-1][c] = true;
            }
            if(r+1<m && grid[r+1][c]==0 && !visited[r+1][c]){
                q.push({r+1, c});
                visited[r+1][c] = true;
            }
            if(c-1>=0 && grid[r][c-1]==0 && !visited[r][c-1]){
                q.push({r, c-1});
                visited[r][c-1] = true;
            }
            if(c+1<n && grid[r][c+1]==0 && !visited[r][c+1]){
                q.push({r, c+1});
                visited[r][c+1] = true;
            }
        }
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            if(grid[i][0]==0 && !visited[i][0]){
                makeOne(i, 0, grid, visited, m, n);
            }
            if(grid[i][n-1]==0 && !visited[i][n-1]){
                makeOne(i, n-1, grid, visited, m, n);
            }
        }
        for(int i=0; i<n; i++){
            if(grid[0][i]==0 && !visited[0][i]){
                makeOne(0, i, grid, visited, m, n);
            }
            if(grid[m-1][i]==0 && !visited[m-1][i]){
                makeOne(m-1, i, grid, visited, m, n);
            }
        }
        int ans = 0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        int r = p.first;
                        int c = p.second;
                        if(r-1>=0 && grid[r-1][c]==0 && !visited[r-1][c]){
                            q.push({r-1, c});
                            visited[r-1][c] = true;
                        }
                        if(r+1<m && grid[r+1][c]==0 && !visited[r+1][c]){
                            q.push({r+1, c});
                            visited[r+1][c] = true;
                        }
                        if(c-1>=0 && grid[r][c-1]==0 && !visited[r][c-1]){
                            q.push({r, c-1});
                            visited[r][c-1] = true;
                        }
                        if(c+1<n && grid[r][c+1]==0 && !visited[r][c+1]){
                            q.push({r, c+1});
                            visited[r][c+1] = true;
                        }
                    }
                    ans++;
                }else{
                    visited[i][j] = true;
                }
            }
        }
        return ans;
    }
};