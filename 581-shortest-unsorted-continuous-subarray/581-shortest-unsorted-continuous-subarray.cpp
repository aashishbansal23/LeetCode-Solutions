class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = 0;
        for(int i=1; i<size; i++){
            if(nums[i] < nums[i-1]){
                left = i-1;
                break;
            }
        }
        for(int i=size-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                right = i+1;
                break;
            }
        }
        int maxx = INT_MIN;
        int minn = INT_MAX;
        for(int i=left; i<=right; i++){
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }
        if(left == right){
            return 0;
        }
        int ans = right-left+1;
        int temp = left;
        while(temp-1>=0 && minn<nums[temp-1]){
            ans++;
            temp--;
        }
        while(right+1<size && maxx>nums[right+1]){
            ans++;
            right++;
        }
        return ans;
        
        
        
        
        
        
        // First Try
        // vector<int> temp = nums;
        // sort(temp.begin(), temp.end());
        // int i=0, j=temp.size()-1;
        // while(i < j){
        //     bool flag = true;
        //     if(nums[i] == temp[i]){
        //         i++;
        //         flag = false;
        //     }
        //     if(nums[j] == temp[j]){
        //         j--;
        //         flag = false;
        //     }
        //     if(flag){
        //         break;
        //     }
        // }
        // if(i >= j){
        //     return 0;
        // }else{
        //     return (j-i+1);
        // }
    }
};