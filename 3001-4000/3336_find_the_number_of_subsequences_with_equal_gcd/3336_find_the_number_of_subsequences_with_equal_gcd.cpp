class Solution {
    int mod = 1e9+7;
    int getGCD(int num1, int num2){
        while(num2 != 0){
            int temp = num2;
            num2 = num1%num2;
            num1 = temp;
        }
        return num1;
    }

    int getSubsequencePairCount(vector<int>& nums, int index, int gcd1, int gcd2, vector<vector<vector<long long>>>& dp){
        if(index == nums.size()){
            if(gcd1 != 0 && gcd1 == gcd2){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[index][gcd1][gcd2] != -1){
            return dp[index][gcd1][gcd2];
        }
        long long temp1 = getSubsequencePairCount(nums, index+1, getGCD(gcd1, nums[index]), gcd2, dp)%mod;
        long long temp2 = getSubsequencePairCount(nums, index+1, gcd1, getGCD(gcd2, nums[index]), dp)%mod;
        long long temp3 = getSubsequencePairCount(nums, index+1, gcd1, gcd2, dp)%mod;
        return dp[index][gcd1][gcd2] = ((temp1+temp2)%mod + temp3)%mod;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int numsSize = nums.size();
        int numsMaxx = 0;
        for(int num:nums){
            numsMaxx = max(numsMaxx, num);
        }
        vector<vector<vector<long long>>> dp(numsSize, vector<vector<long long>>(numsMaxx+1, vector<long long>(numsMaxx+1, -1)));
        return (int)getSubsequencePairCount(nums, 0, 0, 0, dp);
    }
};