class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ourmap;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            ourmap[nums[i]]++;
        }
        for(int i=0; i<nums.size()-1; i++){
            if(ourmap[target-nums[i]] > 0){
                if(target-nums[i] != nums[i] || ourmap[target-nums[i]] > 1){
                    ans.push_back(i);
                    for(int j=i+1; j<nums.size(); j++){
                        if(nums[j] == target-nums[i]){
                            ans.push_back(j);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};