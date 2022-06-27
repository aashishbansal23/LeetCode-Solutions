class Solution {
    void dfs(int r, int c, vector<vector<int>>& isConnected, int n){
        isConnected[r][c] = 0;
        isConnected[r][r] = 0;
        isConnected[c][c] = 0;
        isConnected[c][r] = 0;
        for(int i=0; i<n; i++){
            if(isConnected[c][i]==1){
                dfs(c, i, isConnected, n);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isConnected[i][j]==1){
                    dfs(i, j, isConnected, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};