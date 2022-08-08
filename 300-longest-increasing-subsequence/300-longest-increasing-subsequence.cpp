class Solution {
    // int lengthOfLISRecursion(vector<int>& nums, vector<int>& sequence, int pos){
    //     if(pos == nums.size()){
    //         return sequence.size();
    //     }
    //     int ans = 0;
    //     if(pos == 0){
    //         for(int i=0; i<nums.size(); i++){
    //             sequence.push_back(nums[i]);
    //             ans = max(ans, lengthOfLISRecursion(nums, sequence, i+1));
    //             sequence.pop_back();
    //         }
    //     }else{
    //         for(int i=pos; i<nums.size(); i++){
    //             if(sequence.back() < nums[i]){
    //                 sequence.push_back(nums[i]);
    //                 ans = max(ans, lengthOfLISRecursion(nums, sequence, i+1));
    //                 sequence.pop_back();
    //             }
    //         }
    //     }
    //     return ans;
    // }
    
    int lengthOfLISRecursion(vector<int>& nums, int pre, int next){
        if(next == nums.size()){
            return 0;
        }
        int ans = lengthOfLISRecursion(nums, pre, next+1);
        if(pre==-1 || nums[pre]<nums[next]){
            ans = max(ans, lengthOfLISRecursion(nums, next, next+1)+1);
        }
        return ans;
    }
    
    int lengthOfLISMemoization(vector<int>& nums, int pre, int next, vector<vector<int>>& dp){
        if(next == nums.size()){
            return 0;
        }
        if(dp[pre+1][next] != -1){
            return dp[pre+1][next];
        }
        int ans = lengthOfLISMemoization(nums, pre, next+1, dp);
        if(pre==-1 || nums[pre]<nums[next]){
            ans = max(ans, lengthOfLISMemoization(nums, next, next+1, dp)+1);
        }
        return dp[pre+1][next] = ans;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        // Recursion
        // vector<int> sequence;
        // return lengthOfLISRecursion(nums, sequence, 0);
        // return lengthOfLISRecursion(nums, -1, 0);
        
        // Memoization
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size(), -1));
        return lengthOfLISMemoization(nums, -1, 0, dp);
    }
};