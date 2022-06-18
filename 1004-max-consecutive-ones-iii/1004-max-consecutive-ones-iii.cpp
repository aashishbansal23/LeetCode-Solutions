class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int size = nums.size();
        int start = 0;
        int tempK = k;
        for(int i=0; i<size; i++){
            if(nums[i] == 1){
                mp[nums[i]]++;
                ans = max(ans, i-start+1);
            }else{
                if(k > 0){
                    mp[nums[i]]++;
                    k--;
                    ans = max(ans, i-start+1);
                }else{
                    while(start<=i && k==0){
                        if(nums[start] == 0){
                            mp[nums[start]]--;
                            start++;
                            k++;
                            ans = max(ans, i-start+1);
                            break;
                        }
                        mp[nums[start]]--;
                        start++;
                    }
                    mp[nums[i]]++;
                    k--;
                    ans = max(ans, i-start+1);
                }
            }
        }
        return ans;
    }
};