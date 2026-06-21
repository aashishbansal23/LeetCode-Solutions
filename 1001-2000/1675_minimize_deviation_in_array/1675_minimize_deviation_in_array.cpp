class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minn = INT_MAX;
        for(auto i:nums){
            if((i&1) == 1){
                pq.push(i*2);
                minn = min(minn, i*2);
            }else{
                pq.push(i);
                minn = min(minn, i);
            }
        }
        int ans = pq.top()-minn;
        while((pq.top()&1) == 0){
            int top = pq.top();
            pq.pop();
            top /= 2;
            minn = min(minn, top);
            pq.push(top);
            ans = min(ans, pq.top()-minn);
        }
        return ans;
    }
};