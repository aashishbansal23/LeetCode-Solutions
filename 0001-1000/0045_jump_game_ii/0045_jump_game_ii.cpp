class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return 0;
        }
        int ans = 0;
        int farIndex = 0;
        int currIndex = 0;
        for(int i=0; i<size-1; i++){
            farIndex = max(farIndex,nums[i]+i);
            if(currIndex == i){
                currIndex = farIndex;
                ans++;
            }
        }
        return ans;
    }
};