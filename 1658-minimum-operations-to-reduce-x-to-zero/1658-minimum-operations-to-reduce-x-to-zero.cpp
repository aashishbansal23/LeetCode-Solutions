class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
        int sum = 0;
        for(int i=0; i<size; i++){
            sum += nums[i];
        }
        if(sum < x){
            return -1;
        }else if(sum == x){
            return size;
        }
        int tempSum = sum-x;
        int start = 0;
        int ans = 0;
        sum = 0;
        for(int i=0; i<size; i++){
            sum += nums[i];
            while(sum > tempSum){
                sum -= nums[start++];
            }
            if(sum == tempSum){
                ans = max(ans, i-start+1);
            }
        }
        if(ans == 0){
            return -1;
        }else{
            return size-ans;
        }
    }
};