class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        bool ans = true;
        int i;
        for(i=1; i<len; i++){
            if(nums[i-1] > nums[i]){
                ans = false;
                break;
            }
        }
        if(ans){
            return true;
        }
        int check = i;
        i++;
        if(i == len){
            if(nums[len-1] <= nums[0]){
                return true;
            }else{
                return false;
            }
        }
        ans = true;
        while(check != i){
            if(nums[i-1] > nums[i]){
                ans = false;
                break;
            }
            i++;
            if(i == len){
                if(nums[0] < nums[len-1]){
                    ans = false;
                    break;
                }else{
                    i = 1;
                }
            }
        }
        return ans;
    }
};