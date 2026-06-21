class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans = 0;
        int diff = INT_MAX;
        for(int i=0; i<len-2; i++){
            int j = i+1;
            int k = len-1;
            int curr = target-nums[i];
            while(j < k){
                int sum = nums[j]+nums[k];
                if(abs(target-nums[i]-nums[j]-nums[k]) < diff){
                    diff = abs(target-nums[i]-nums[j]-nums[k]);
                    ans = nums[i]+nums[j]+nums[k];
                }
                if(sum < curr){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};