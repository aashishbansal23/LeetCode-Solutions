class Solution {
    void coinChange_help(vector<int>& coins, vector<int>& dp){
        dp[0] = 0;
        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j] <= i){
                    if(dp[i-coins[j]] != INT_MAX){
                        dp[i] = min(dp[i], dp[i-coins[j]]+1);
                    }
                }
            }
        }
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        coinChange_help(coins, dp);
        if(dp[amount] == INT_MAX){
            return -1;
        }else{
            return dp[amount];
        }
    }
};