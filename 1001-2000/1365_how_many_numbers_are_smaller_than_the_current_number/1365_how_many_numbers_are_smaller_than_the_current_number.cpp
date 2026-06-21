class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        for(int i=0; i<temp.size(); i++){
            if(i == 0){
                mp[temp[i]] = 0;
            }else if(temp[i] > temp[i-1]){
                mp[temp[i]] = i;
            }
        }
        temp.clear();
        for(int i=0; i<nums.size(); i++){
            temp.push_back(mp[nums[i]]);
        }
        return temp;
    }
};