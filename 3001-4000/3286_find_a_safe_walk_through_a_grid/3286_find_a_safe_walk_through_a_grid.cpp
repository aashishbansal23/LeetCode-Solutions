class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        int x[] = {1, 0, -1, 0};
        int y[] = {0, 1, 0, -1};
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<tuple<int, int, int>> q;
        if(health-grid[0][0] <= 0){
            return false;
        }
        q.push({0, 0, health-grid[0][0]});
        visited[0][0] = health-grid[0][0];
        while(!q.empty()){
            auto[xt, yt, ht] = q.front();
            q.pop();
            if(xt==m-1 && yt==n-1){
                return true;
            }
            for(int i=0; i<4; i++){
                int dx = xt+x[i];
                int dy = yt+y[i];
                if(dx<0 || dx>=m || dy<0 || dy>=n){
                    continue;
                }
                int dh = ht-grid[dx][dy];
                if(dh <= 0){
                    continue;
                }
                if(dh > visited[dx][dy]){
                    visited[dx][dy] = dh;
                    q.push({dx, dy, dh});
                }
            }
        }
        return false;
    }
};