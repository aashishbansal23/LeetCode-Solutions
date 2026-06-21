class Solution {
    int help(int i, int l, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, vector<vector<vector<int>>>& dp){
        if(t > target){
            return INT_MAX/2;
        }
        if(i == m){
            if(t == target){
                return 0;
            }else{
                return INT_MAX/2;
            }
        }else{
            if(dp[i][l][t] != -1){
                return dp[i][l][t];
            }
            int ans = INT_MAX/2;
            if(houses[i] == 0){
                for(int j=0; j<n; j++){
                    ans = min(ans, cost[i][j]+help(i+1, j+1, (l==j+1)?t:t+1, houses, cost, m, n, target, dp));
                }
            }else{
                ans = min(ans, help(i+1, houses[i], (houses[i]==l)?t:t+1, houses, cost, m, n, target, dp));
            }
            return dp[i][l][t]=ans;
        }
    }
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        int ans = help(0, 0, 0, houses, cost, m, n, target, dp);
        if(ans == INT_MAX/2){
            return -1;
        }else{
            return ans;
        }
    }
};