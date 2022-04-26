class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj;
        int len = points.size();
        for(int i=0; i<len; i++){
            vector<pair<int, int>> temp;
            for(int j=0; j<len; j++){
                if(j == i){
                    continue;
                }else{
                    pair<int, int> p;
                    int dist = abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                    p = {j, dist};
                    temp.push_back(p);
                }
            }
            adj.push_back(temp);
        }
        int inf = INT_MAX;
        vector<int> key(len, inf);
        vector<bool> mstSet(len, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        key[0] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            mstSet[u] = true;
            for(auto ele:adj[u]){
                int v = ele.first;
                int w = ele.second;
                if(mstSet[v]==false && w<key[v]){
                    key[v] = w;
                    pq.push({w, v});
                }
            }
        }
        long long ans = 0;
        for(int x:key){
            ans += x;
        }
        return ans;
    }
};