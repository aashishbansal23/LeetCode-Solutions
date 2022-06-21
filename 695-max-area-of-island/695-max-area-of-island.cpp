class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area = 0;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    area++;
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        int r = p.first;
                        int c = p.second;
                        if(r-1>=0 && grid[r-1][c]==1 && !visited[r-1][c]){
                            q.push({r-1,c});
                            visited[r-1][c] = true;
                            area++;
                        }
                        if(r+1<m && grid[r+1][c]==1 && !visited[r+1][c]){
                            q.push({r+1,c});
                            visited[r+1][c] = true;
                            area++;
                        }
                        if(c-1>=0 && grid[r][c-1]==1 && !visited[r][c-1]){
                            q.push({r,c-1});
                            visited[r][c-1] = true;
                            area++;
                        }
                        if(c+1<n && grid[r][c+1]==1 && !visited[r][c+1]){
                            q.push({r,c+1});
                            visited[r][c+1] = true;
                            area++;
                        }
                    }
                    ans = max(ans, area);
                }else{
                    visited[i][j] = true;
                }
            }
        }
        return ans;
    }
};