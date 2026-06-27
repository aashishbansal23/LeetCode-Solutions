class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int numsLength = nums.size();
        for(int i=0; i<numsLength; i++){
            int count = 0;
            for(int j=i; j<numsLength; j++){
                if(nums[j] == target){
                    count++;
                }
                if(2*count > j-i+1){
                    ans++;
                }
            }
        }
        return ans;
    }
};