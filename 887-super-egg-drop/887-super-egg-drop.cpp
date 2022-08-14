class Solution {
    int superEggDropRecursion(int eggs, int floors){
        if(floors==0 || floors==1){
            return floors;
        }
        if(eggs == 1){
            return floors;
        }
        int ans = INT_MAX;
        for(int k=1; k<=floors; k++){
            int tempAns = 1+max(superEggDropRecursion(eggs-1, k-1), superEggDropRecursion(eggs, floors-k));
            ans = min(ans, tempAns);
        }
        return ans;
    }
    
    int superEggDropMemoization(int eggs, int floors, vector<vector<int>>& dp){
        if(floors==0 || floors==1){
            return floors;
        }
        if(eggs == 1){
            return floors;
        }
        if(dp[eggs][floors] != -1){
            return dp[eggs][floors];
        }
        int ans = INT_MAX;
        for(int k=1; k<=floors; k++){
            int taken = 0;
            int notTaken = 0;
            if(dp[eggs-1][k-1] != -1){
                taken = dp[eggs-1][k-1];
            }else{
                dp[eggs-1][k-1] = superEggDropMemoization(eggs-1, k-1, dp);
                taken = dp[eggs-1][k-1];
            }
            if(dp[eggs][floors-k] != -1){
                notTaken = dp[eggs][floors-k];
            }else{
                dp[eggs][floors-k] = superEggDropMemoization(eggs, floors-k, dp);
                notTaken = dp[eggs][floors-k];
            }
            int tempAns = 1+max(taken, notTaken);
            // int tempAns = 1+max(superEggDropMemoization(eggs-1, k-1, dp), superEggDropMemoization(eggs, floors-k, dp));
            ans = min(ans, tempAns);
        }
        return dp[eggs][floors]=ans;
    }
    
    int superEggDropDP(int eggs, int floors){
        vector<vector<int>> dp(eggs+1, vector<int>(floors+1, 0));
        int i = 0;
        while(dp[eggs][i] < floors){
            i++;
            for(int k=1; k<=eggs; k++){
                dp[k][i] = dp[k-1][i-1]+dp[k][i-1]+1;
            }
        }
        return i;
    }
    
public:
    int superEggDrop(int k, int n) {
        // Recursion
        // return superEggDropRecursion(k, n);
        
        // Memoization Gives TLE
        // vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        // return superEggDropMemoization(k, n, dp);
        
        
        return superEggDropDP(k, n);
    }
};