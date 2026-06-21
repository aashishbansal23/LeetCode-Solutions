class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // 0/1 BFS
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int direction[] = {4, 3, 2, 1};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> q;
        q.push_front({0,0});
        dist[0][0] = 0;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop_front();
            for(int i=0; i<4; i++){
                int x = r+dx[i];
                int y = c+dy[i];
                if(x>=0 && x<m && y>=0 && y<n){
                    int wt = 0;
                    if(direction[i] != grid[r][c]){
                        wt = 1;
                    }
                    if(dist[r][c]+wt < dist[x][y]){
                        dist[x][y] = dist[r][c]+wt;
                        if(wt == 1){
                            q.push_back({x,y});
                        }else{
                            q.push_front({x,y});
                        }
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};