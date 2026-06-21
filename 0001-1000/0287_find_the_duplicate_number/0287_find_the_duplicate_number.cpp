class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[nums[0]];
        int h = nums[nums[nums[0]]];
        while(t != h){
            t = nums[t];
            h = nums[nums[h]];
        }
        t=nums[0];
        while(t != h){
            t = nums[t];
            h = nums[h];
        }
        return h;
    }
};