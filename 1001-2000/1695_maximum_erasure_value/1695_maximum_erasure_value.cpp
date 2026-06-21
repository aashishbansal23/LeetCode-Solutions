class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int temp = 0;
        int start = 0;
        for(int i=0; i<size; i++){
            mp[nums[i]]++;
            temp += nums[i];
            while(mp[nums[i]] != 1){
                temp -= nums[start];
                mp[nums[start++]]--;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};