class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        if(size < 3){
            return -1;
        }
        
        int low = 1;
        int high = size-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid]>arr[mid-1]){
                low = mid;
            }else{
                high = mid;
            }
        }
        return low;
        
        
        
        
        
        
        
        
        
//         int size = arr.size();
//         if(size < 3){
//             return -1;
//         }
        
//         int ans = -1;
//         int pre = arr[0];
//         int i = 1;
//         while(i<size && arr[i]>pre){
//             pre = arr[i];
//             i++;
//         }
//         if(i==size || i==1){
//             return -1;
//         }
        
//         ans = i-1;
        
//         while(i<size && pre>arr[i]){
//             pre = arr[i];
//             i++;
//         }
        
//         if(i<size || i==ans){
//             return -1;
//         }
        
//         return ans;
    }
};