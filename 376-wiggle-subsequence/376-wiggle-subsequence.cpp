class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return 1;
        }
        int pre = nums[1]-nums[0];
        int ans;
        if(pre == 0){
            ans = 1;
        }else{
            ans = 2;
        }
        for(int i=2; i<size; i++){
            int diff = nums[i]-nums[i-1];
            if((pre>=0 && diff<0) || (pre<=0 && diff>0)){
                ans++;
                pre = diff;
            }
        }
        return ans;
    }
};