class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int low;
        int high;
        for(low=size-2; low>=0; low--){
            if(nums[low] < nums[low+1]){
                break;
            }
        }
        if(low < 0){
            reverse(nums.begin(), nums.end());
        }else{
            for(high=size-1; high>low; high--){
                if(nums[high] > nums[low]){
                    break;
                }
            }
            swap(nums[low], nums[high]);
            reverse(nums.begin()+low+1, nums.end());
        }
    }
};