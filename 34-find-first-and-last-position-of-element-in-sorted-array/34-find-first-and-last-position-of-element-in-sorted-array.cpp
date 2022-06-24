class Solution {
//     int helper(vector<int>& nums, int l, int h, int target, int check){
//         if(l > h){
//             return -1;
//         }
        
//         int ans = -1;
//         while(l <= h){
//             int mid = l+(h-l)/2;
//             if(nums[mid] == target){
//                 ans = mid;
//                 if(check == -1){
//                     h = mid-1;
//                 }else if(check == 1){
//                     l = mid+1;
//                 }
//             }else if(nums[mid] > target){
//                 h = mid-1;
//             }else{
//                 l = mid+1;
//             }
//         }
//         return ans;
//     }
    
    
    int findLeft(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }else if(nums[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
    
    int findRight(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }else if(nums[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        vector<int> ans(2, -1);
        if(left == -1 && right == -1){
            return ans;
        }else if(left == -1){
            ans[0] = right;
        }else if(right == -1){
            ans[0] = left;
        }else{
            ans[0] = left;
            ans[1] = right;
        }
        return ans;
        
        
        
        
        
        
//         int size = nums.size();
//         vector<int> ans(2, -1);
        
//         int low = 0;
//         int high = size-1;
        
//         while(low <= high){
//             int mid = low+(high-low)/2;
//             if(nums[mid] == target){
//                 int temp1 = helper(nums, low, mid-1, target, -1);
//                 int temp2 = helper(nums, mid+1, high, target, 1);
//                 if(temp1==-1 && temp2==-1){
//                     ans[0] = mid;
//                     ans[1] = mid;
//                 }else if(temp1 == -1){
//                     ans[0] = mid;
//                     ans[1] = temp2;
//                 }else if(temp2 == -1){
//                     ans[0] = temp1;
//                     ans[1] = mid;
//                 }else{
//                     ans[0] = temp1;
//                     ans[1] = temp2;
//                 }
//                 return ans;
//             }else if(nums[mid] > target){
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
    }
};