class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
            else if(nums[l] <= nums[mid])
            {
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};

// class Solution {
//     int getPivot(vector<int>& nums){
//         int low = 0;
//         int high = nums.size()-1;
//         int ans = 0;
//         while(low <= high){
//             int mid = low+(high-low)/2;
//             if(nums[mid] < nums[0]){
//                 ans = mid;
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
    
// public:
//     bool search(vector<int>& nums, int target) {
        
//         int pivot = getPivot(nums);
//         cout << pivot << endl;
//         return true;
//     }
// };