class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==n*n || q.size()==0){
            return -1;
        }
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            while(size > 0){
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if(r-1>=0 && grid[r-1][c]==0){
                    q.push({r-1,c});
                    grid[r-1][c] = 1;
                    flag = true;
                }
                if(r+1<n && grid[r+1][c]==0){
                    q.push({r+1,c});
                    grid[r+1][c] = 1;
                    flag = true;
                }
                if(c-1>=0 && grid[r][c-1]==0){
                    q.push({r,c-1});
                    grid[r][c-1] = 1;
                    flag = true;
                }
                if(c+1<n && grid[r][c+1]==0){
                    q.push({r,c+1});
                    grid[r][c+1] = 1;
                    flag = true;
                }
                size--;
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};