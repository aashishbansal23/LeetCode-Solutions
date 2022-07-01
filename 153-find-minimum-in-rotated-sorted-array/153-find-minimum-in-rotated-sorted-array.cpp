class Solution {
    int getPivot(vector<int>& nums){
        int s=0, e=nums.size()-1;
        while(s < e){
            int mid = s+(e-s)/2;
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }else{
                e = mid;
            }
        }
        return s;
    }
    
public:
    int findMin(vector<int>& nums) {
        int pivot = getPivot(nums);
        if(pivot==nums.size()-1 && nums[pivot]>nums[0]){
            return nums[0];
        }
        return nums[pivot];
    }
};