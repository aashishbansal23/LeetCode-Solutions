class Solution {
public:
    bool isPossible(vector<int>& target) {
        int size = target.size();
        long long sum = 0;
        priority_queue<int> pq;
        for(int i=0; i<size; i++){
            sum += target[i];
            pq.push(target[i]);
        }
        if(sum-pq.top() > INT_MAX){
            return false;
        }
        while(!pq.empty() && pq.top()!=1){
            int top = pq.top();
            pq.pop();
            sum -= top;
            if(sum>top || sum==0){
                return false;
            }
            top = top%sum;
            if(top==0 && sum!=1){
                return false;
            }
            sum += top;
            pq.push(top);
        }
        return true;
    }
};