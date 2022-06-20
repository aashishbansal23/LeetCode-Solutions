class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '0'){
                    visited[i][j] = true;
                }else if(!visited[i][j]){
                    ans++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        int r = p.first;
                        int c = p.second;
                        if(r-1>=0 && grid[r-1][c]=='1' && !visited[r-1][c]){
                            q.push(make_pair(r-1, c));
                            visited[r-1][c] = true;
                        }
                        if(r+1<m && grid[r+1][c]=='1' && !visited[r+1][c]){
                            q.push(make_pair(r+1, c));
                            visited[r+1][c] = true;
                        }
                        if(c-1>=0 && grid[r][c-1]=='1' && !visited[r][c-1]){
                            q.push(make_pair(r, c-1));
                            visited[r][c-1] = true;
                        }
                        if(c+1<n && grid[r][c+1]=='1' && !visited[r][c+1]){
                            q.push(make_pair(r, c+1));
                            visited[r][c+1] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};