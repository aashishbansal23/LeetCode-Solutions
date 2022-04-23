class Solution {
    bool checkForT(vector<int>& nums, int i, int j, int t){
        if(i >= j){
            return false;
        }
        
        long long num1 = nums[i];
        long long num2 = nums[j];
        long long temp = abs(num2-num1);
        if(temp <= t){
            return true;
        }else if(checkForT(nums, i+1, j, t) || checkForT(nums, i, j-1, t)){
            return true;
        }else{
            return false;
        }
    }
    
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int, int>> temp;
        int len = nums.size();
        for(int i=0; i<len; i++){
            temp.push_back(make_pair(nums[i], i));
        }
        sort(temp.begin(), temp.end());
        sort(nums.begin(), nums.end());
        bool ans = false;
        for(int i=0; i<len; i++){
            long long value = 1LL*nums[i]+t;
            int index = upper_bound(nums.begin()+i+1, nums.end(), value)-nums.begin();
            for(int j=i+1; j<index; j++){
                if(abs(1LL*temp[j].second-1LL*temp[i].second)<=k && abs(1LL*temp[j].first-1LL*temp[i].first<=t)){
                    ans = true;
                    break;
                }
            }
            if(ans){
                break;
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // First Try Gives TLE
        // if(k == 0){
        //     return false;
        // }
        // int len = nums.size();
        // if(len <= k){
        //     vector<int> temp = nums;
        //     sort(temp.begin(), temp.end());
        //     if(checkForT(temp, 0, len-1, t)){
        //         return true;
        //     }else{
        //         return false;
        //     }
        // }
        // vector<int> temp = nums;
        // for(int i=0; i<len-k; i++){
        //     temp = nums;
        //     sort(temp.begin()+i, temp.begin()+i+k);
        //     if(checkForT(temp, i, i+k, t)){
        //         return true;
        //     }
        // }
        // return false;
    }
};