class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid = low;
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target){
                break;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(nums[mid] < target){
             mid++;
        }
        return mid;
    }
};