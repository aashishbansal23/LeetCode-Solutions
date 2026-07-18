class Solution {
public:
    int findGCD(vector<int>& nums) {
        int numsMin = INT_MAX;
        int numsMax = INT_MIN;
        for(int num:nums){
            numsMin = min(numsMin, num);
            numsMax = max(numsMax, num);
        }
        return gcd(numsMin, numsMax);
    }
};