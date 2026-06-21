class Solution {
    int getCount(vector<int>& nums, int mid){
        int count = 0;
        for(auto i:nums){
            if(i >= mid){
                count++;
            }
            if(count > mid){
                return INT_MAX;
            }
        }
        return count;
    }
    
public:
    int specialArray(vector<int>& nums) {
        int size = nums.size();
        int low = 0;
        int high = -1;
        for(int i=0; i<size; i++){
            high = max(high, nums[i]);
        }
        
        while(low <= high){
            int mid = low+(high-low)/2;
            int count = getCount(nums, mid);
            if(count == mid){
                return mid;
            }else if(count > mid){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};