class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i=0, j=0;
        int ans = 0;
        while(i<size1 && j<size2){
            if(nums1[i] > nums2[j]){
                i++;
            }else{
                ans = max(ans, j-i);
                j++;
            }
        }
        return ans;
        
        
        
        // Second Try
        // int size1 = nums1.size();
        // int size2 = nums2.size();
        // int ans = 0;
        // for(int i=0; i<size1; i++){
        //     int low = i;
        //     int high = size2-1;
        //     while(low <= high){
        //         int mid = low+(high-low)/2;
        //         if(nums2[mid] >= nums1[i]){
        //             ans = max(ans, mid-i);
        //             low = mid+1;
        //         }else{
        //             high = mid-1;
        //         }
        //     }
        // }
        // return ans;
        
        
        
        
        // First Try Brute Force Gives TLE
        // int size1 = nums1.size();
        // int size2 = nums2.size();
        // int ans = 0;
        // for(int i=0; i<size1; i++){
        //     for(int j=i; j<size2; j++){
        //         if(nums2[j] >= nums1[i]){
        //             ans = max(ans, j-i);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return ans;
    }
};