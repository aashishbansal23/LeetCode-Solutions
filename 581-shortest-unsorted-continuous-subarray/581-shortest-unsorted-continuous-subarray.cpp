class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int i=0, j=temp.size()-1;
        while(i < j){
            bool flag = true;
            if(nums[i] == temp[i]){
                i++;
                flag = false;
            }
            if(nums[j] == temp[j]){
                j--;
                flag = false;
            }
            if(flag){
                break;
            }
        }
        if(i >= j){
            return 0;
        }else{
            return (j-i+1);
        }
    }
};