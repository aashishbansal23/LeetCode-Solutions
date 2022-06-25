class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        bool flag = true;
        int i = size-1;
        int index = -1;
        int val = 0;
        for(i=size-1; i>0; i--){
            if(nums[i-1] > nums[i]){
                if(flag){
                    index = i-1;
                    val = nums[i-1];
                    nums[i-1] = nums[i];
                    flag = false;
                }else{
                    break;
                }
            }
        }
        if(i == 0){
            return true;
        }
        nums[index] = val;
        flag = true;
        for(i=1; i<size; i++){
            if(nums[i-1] > nums[i]){
                if(flag){
                    nums[i] = nums[i-1];
                    flag = false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};