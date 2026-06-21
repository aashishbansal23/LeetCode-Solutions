class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<pair<int,int>,int>> q; // {{r,c}, k}
        if(grid[0][0] == 0){
            q.push({{0,0},k});
            visited[0][0] = k;
        }else if(k>0 && grid[0][0]==1){
            q.push({{0,0},k-1});
            visited[0][0] = k-1;
        }
        int ans = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<pair<int,int>,int> p = q.front();
                int r = p.first.first;
                int c = p.first.second;
                int t = p.second;
                q.pop();
                if(r==m-1 && c==n-1){
                    return ans;
                }
                for(int i=0; i<4; i++){
                    int x = r+dx[i];
                    int y = c+dy[i];
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(grid[x][y] == 0){
                            if(visited[x][y]==-1 || visited[x][y]<t){
                                q.push({{x,y},t});
                                visited[x][y] = t;
                            }
                        }else if(t > 0){
                            if(visited[x][y]==-1 || visited[x][y]<t-1){
                                q.push({{x,y},t-1});
                                visited[x][y] = t-1;
                            }
                        }
                    }
                }
                size--;
            }
            ans++;
        }
        return -1;
    }
};