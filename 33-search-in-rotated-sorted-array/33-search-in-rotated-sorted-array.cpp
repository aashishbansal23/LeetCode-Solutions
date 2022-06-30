class Solution {
    int getPivot(vector<int>& nums){
        int size = nums.size();
        int s = 0;
        int e = size-1;
        while(s < e){
            int mid = s+(e-s)/2;
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }else{
                e = mid;            }
        }
        return s;
    }
    
    int search(vector<int>& nums, int s, int e, int target){
        if(s > e){
            return -1;
        }
        
        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0){
            return -1;
        }
        
        int pivot = getPivot(nums);
        // cout << pivot << endl;
        if(nums[pivot] == target){
            return pivot;
        }else if(target>=nums[0]){
            return search(nums, 0, pivot, target);
        }else if(target>=nums[pivot] && target<=nums[size-1]){
            return search(nums, pivot, size-1, target);
        }else{
            return search(nums, 0, size-1, target);
        }
    }
};