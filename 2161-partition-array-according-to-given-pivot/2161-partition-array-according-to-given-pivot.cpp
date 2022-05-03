class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int size = nums.size();
        vector<int> ans(size, pivot);
        int k = 0;
        for(int i=0; i<size; i++){
            if(nums[i] < pivot){
                ans[k++] = nums[i];
            }
        }
        k = size-1;
        for(int i=size-1; i>=0; i--){
            if(nums[i] > pivot){
                ans[k--] = nums[i];
            }
        }
        return ans;
    }
};