class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m2 = grid2.size();
        int n2 = grid2[0].size();
        vector<vector<bool>> visited(m2, vector<bool>(n2, false));
        int ans = 0;
        for(int i=0; i<m2; i++){
            for(int j=0; j<n2; j++){
                if(grid2[i][j]==1 && !visited[i][j]){
                    bool flag = true;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        int r = p.first;
                        int c = p.second;
                        if(grid1[r][c] != 1){
                            flag = false;
                        }
                        if(r-1>=0 && grid2[r-1][c]==1 && !visited[r-1][c]){
                            q.push({r-1,c});
                            visited[r-1][c] = true;
                        }
                        if(r+1<m2 && grid2[r+1][c]==1 && !visited[r+1][c]){
                            q.push({r+1,c});
                            visited[r+1][c] = true;
                        }
                        if(c-1>=0 && grid2[r][c-1]==1 && !visited[r][c-1]){
                            q.push({r,c-1});
                            visited[r][c-1] = true;
                        }
                        if(c+1<n2 && grid2[r][c+1]==1 && !visited[r][c+1]){
                            q.push({r,c+1});
                            visited[r][c+1] = true;
                        }
                    }
                    if(flag){
                        ans++;
                    }
                }else{
                    visited[i][j] = true;
                }
            }
        }
        return ans;
    }
};