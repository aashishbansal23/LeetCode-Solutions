class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                ans[r][c] = dist;
                if(r-1>=0 && mat[r-1][c]==1 && ans[r-1][c]==-1){
                    q.push({r-1,c});
                    ans[r-1][c] = 0;
                }
                if(r+1<m && mat[r+1][c]==1 && ans[r+1][c]==-1){
                    q.push({r+1,c});
                    ans[r+1][c] = 0;
                }
                if(c-1>=0 && mat[r][c-1]==1 && ans[r][c-1]==-1){
                    q.push({r,c-1});
                    ans[r][c-1] = 0;
                }
                if(c+1<n && mat[r][c+1]==1 && ans[r][c+1]==-1){
                    q.push({r,c+1});
                    ans[r][c+1] = 0;
                }
                size--;
            }
            dist++;
        }
        return ans;
    }
};