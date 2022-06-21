class Solution {
    void makeZero(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n){
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            grid[r][c] = 0;
            if(r-1>=0 && grid[r-1][c]==1 && !visited[r-1][c]){
                q.push({r-1, c});
                visited[r-1][c] = true;
            }
            if(r+1<m && grid[r+1][c]==1 && !visited[r+1][c]){
                q.push({r+1, c});
                visited[r+1][c] = true;
            }
            if(c-1>=0 && grid[r][c-1]==1 && !visited[r][c-1]){
                q.push({r, c-1});
                visited[r][c-1] = true;
            }
            if(c+1<n && grid[r][c+1]==1 && !visited[r][c+1]){
                q.push({r, c+1});
                visited[r][c+1] = true;
            }
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && !visited[i][0]){
                makeZero(i, 0, grid, visited, m, n);
            }
            if(grid[i][n-1]==1 && !visited[i][n-1]){
                makeZero(i, n-1, grid, visited, m, n);
            }
        }
        for(int i=0; i<n; i++){
            if(grid[0][i]==1 && !visited[0][i]){
                makeZero(0, i, grid, visited, m, n);
            }
            if(grid[m-1][i]==1 && !visited[m-1][i]){
                makeZero(m-1, i, grid, visited, m, n);
            }
        }
        int ans = 0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};