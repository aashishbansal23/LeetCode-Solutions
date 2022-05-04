class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=size-1;
        int ans = 0;
        while(i < j){
            if(nums[i]+nums[j] == k){
                i++;
                j--;
                ans++;
            }else if(nums[i]+nums[j] > k){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};