class Solution {
    int solve(vector<vector<int>>& dp, int s, int e){
        if(s >= e){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int ans = INT_MAX;
        for(int i=s; i<=e; i++){
            ans = min(ans, i+max(solve(dp, s, i-1),solve(dp, i+1, e)));
        }
        dp[s][e] = ans;
        return ans;
    }
    
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(dp, 1, n);
    }
};