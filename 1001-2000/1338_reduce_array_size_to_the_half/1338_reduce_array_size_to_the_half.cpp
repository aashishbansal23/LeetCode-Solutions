class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> frequency;
        for(auto i:arr){
            frequency[i]++;
        }
        int ans = 0;
        int count = 0;
        priority_queue<int> pq;
        for(auto f:frequency){
            pq.push(f.second);
        }
        while(count < arr.size()/2){
            count += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};