class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto num:nums){
            sum += num;
        }
        if(target>sum || target<-sum || ((sum+target)&1)!=0){
            return 0;
        }
        sum += target;
        sum = (sum>>1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};