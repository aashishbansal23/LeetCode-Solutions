class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans = 0;
        int size = stones.size();
        priority_queue<int> pq;
        for(int i=0; i<size; i++){
            pq.push(stones[i]);
        }
        while(pq.size() != 1){
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            pq.push(abs(temp1-temp2));
        }
        return pq.top();
    }
};