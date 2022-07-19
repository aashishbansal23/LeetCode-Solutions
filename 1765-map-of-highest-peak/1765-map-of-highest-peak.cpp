class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int, int>> q;
        int height = 2;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                isWater[r][c] = height;
                for(int i=0; i<4; i++){
                    int x = r+dx[i];
                    int y = c+dy[i];
                    while(x>=0 && x<m && y>=0 && y<n && isWater[x][y]==0){
                        q.push({x,y});
                        isWater[x][y] = 1;
                    }
                }
            }
            height++;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                isWater[i][j] -= 2;
            }
        }
        return isWater;
    }
};