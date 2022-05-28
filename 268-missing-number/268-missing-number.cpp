class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i=0; i<n; i++){
            ans = ans^i^nums[i];
        }
        return ans;
        // int maxx = INT_MIN;
        // int sum = 0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] > maxx){
        //         maxx = nums[i];
        //     }
        //     sum+=nums[i];
        // }
        // int sum1 = (nums.size()*(nums.size()+1))/2;
        // return sum1-sum;
    }
};