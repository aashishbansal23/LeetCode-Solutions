class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int size = nums.size();
        int ans = 0;
        int temp = 0;
        int j = 0;
        for(int i=0; i<size; i++){
            if(nums[i] > right){
                temp = 0;
                j = i+1;
            }else if(nums[i] >= left){
                temp = i-j+1;
                ans += temp;
            }else{
                ans += temp;
            }
        }
        return ans;
    }
};