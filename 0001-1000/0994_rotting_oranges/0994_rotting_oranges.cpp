class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = -1;
                }
            }
        }
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size-- > 0){
                auto [r,c] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int x = r+dx[i];
                    int y = c+dy[i];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y] = -1;
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return max(ans-1, 0);
    }
};