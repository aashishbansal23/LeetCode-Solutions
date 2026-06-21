class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> mp;
        int k = 2;
        int zeros = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int temp = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = k;
                    temp++;
                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();
                        for(int a=0; a<4; a++){
                            int x = r+dx[a];
                            int y = c+dy[a];
                            if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                                q.push({x,y});
                                grid[x][y] = k;
                                temp++;
                            }
                        }
                    }
                    mp[k] = temp;
                    k++;
                }else if(grid[i][j] == 0){
                    zeros++;
                }
            }
        }
        if(zeros == 0){
            return n*n;
        }else if(zeros == n*n){
            return 1;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    set<pair<int,int>> st;
                    for(int a=0; a<4; a++){
                        int x = i+dx[a];
                        int y = j+dy[a];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!=0){
                            st.insert({grid[x][y], mp[grid[x][y]]});
                        }
                    }
                    int temp = 1;
                    for(auto s:st){
                        temp += s.second;
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};