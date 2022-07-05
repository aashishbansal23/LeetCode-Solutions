class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto num:nums){
            mp[num] = true;
        }
        int ans = 0;
        for(auto num:nums){
            if(mp.count(num-1) == 0){
                int temp = num;
                int count = 0;
                while(mp.count(temp) > 0){
                    count++;
                    temp++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};