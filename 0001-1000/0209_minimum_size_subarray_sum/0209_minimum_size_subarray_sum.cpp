class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int ans = size+1;
        int start = 0;
        int sum = 0;
        for(int i=0; i<size; i++){
            sum += nums[i];
            while(sum >= target){
                ans = min(ans, i-start+1);
                sum -= nums[start++];
            }
        }
        if(ans == size+1){
            return 0;
        }else{
            return ans;
        }
    }
};