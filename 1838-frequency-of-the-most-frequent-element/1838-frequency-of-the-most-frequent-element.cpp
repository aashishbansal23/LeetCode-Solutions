class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        long long sum = k;
        for(i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum < (long long)nums[i]*(i-j+1)){
                sum -= nums[j++];
            }
        }
        return i-j;
    }
};