class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i < j){
            if((nums[i]&1)==1 && (nums[j]&1)==0){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }else if((nums[i]&1) == 0){
                i++;
            }else if((nums[j]&1) == 1){
                j--;
            }
        }
        return nums;
    }
};