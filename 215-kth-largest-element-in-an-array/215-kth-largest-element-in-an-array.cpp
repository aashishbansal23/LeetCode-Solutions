class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        k = len-k;
        if(k < 0){
            return -1;
        }else{
            return nums[k];
        }
    }
};