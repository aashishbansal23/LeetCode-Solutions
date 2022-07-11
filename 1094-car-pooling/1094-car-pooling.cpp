class Solution {
    bool static compator(vector<int>& v1, vector<int>& v2){
        return v1[1]<v2[1];
    }
    
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), compator);
        int count = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto trip:trips){
            int pass = trip[0];
            int from = trip[1];
            int to = trip[2];
            while(!pq.empty() && pq.top().first<=from){
                count -= pq.top().second;
                pq.pop();
            }
            if(count+pass > capacity){
                return false;
            }
            count += pass;
            pq.push({to,pass});
        }
        return true;
    }
};