class Solution {
    void combinationSum4Recursion(vector<int>& nums, int target, int& ans){
        if(target == 0){
            ans++;
            return ;
        }
        if(target < 0){
            return ;
        }
        for(auto num:nums){
            if(num <= target){
                combinationSum4Recursion(nums, target-num, ans);
            }
        }
    }
    
    void combinationSum4Memoization(vector<int>& nums, int target, vector<long long>& dp){
        set<int> st;
        for(auto num:nums){
            st.insert(num);
            if(num <= target){
                dp[num]++;
            }
        }
        for(int i=1; i<target+1; i++){
            for(int j=1; j<i; j++){
                if(st.count(i-j) > 0){
                    dp[i] += dp[j];
                    dp[i] = dp[i]%INT_MAX;
                }
            }
        }
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Recursion
        // int ans = 0;
        // combinationSum4Recursion(nums, target, ans);
        // return ans;
        
        // return 0;
        vector<long long> dp(target+1, 0);
        combinationSum4Memoization(nums, target, dp);
        return dp[target];
    }
};