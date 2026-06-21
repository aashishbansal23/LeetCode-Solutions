class Solution {
    bool canPartitionDP(vector<int>& nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i=0; i<n+1; i++){
            dp[i][0] = true;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    
public:
    bool canPartition(vector<int>& nums) {
        // Same as Subset Sum Problem gfg
        int sum = 0;
        for(auto num:nums){
            sum += num;
        }
        if((sum&1) == 1){
            return false;
        }
        return canPartitionDP(nums, sum/2);
    }
};