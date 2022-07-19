class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size = nums.size();
        for(int i=1; i<size; i++){
            for(int j=0; j<size-i; j++){
                nums[j] += nums[j+1];
                nums[j] %= 10;
            }
        }
        return nums[0];
    }
};