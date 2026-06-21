class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if(size < 3){
            return false;
        }
        vector<int> pre_min(size, nums[0]);
        for(int i=1; i<size; i++){
            pre_min[i] = min(pre_min[i-1], nums[i]);
        }
        stack<int> st;
        for(int i=size-1; i>=0; i--){
            while(!st.empty() && st.top()<=pre_min[i]){
                st.pop();
            }
            if(!st.empty() && st.top()<nums[i]){
                return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
};