class Solution {
    int findPathsDP(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp){
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n){
            return 1;
        }
        if(maxMove == 0){
            return 0;
        }
        int mod = 1e9+7;
        if(dp[maxMove][startRow][startColumn] != -1){
            return dp[maxMove][startRow][startColumn]%mod;
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        for(int i=0; i<4; i++){
            int x = startRow+dx[i];
            int y = startColumn+dy[i];
            ans += (findPathsDP(m, n, maxMove-1, x, y, dp)%mod);
            ans = ans%mod;
        }
        dp[maxMove][startRow][startColumn] = ans;
        return ans;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return findPathsDP(m, n, maxMove, startRow, startColumn, dp);
    }
};