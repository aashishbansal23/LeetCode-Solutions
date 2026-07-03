class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> adjList;

    bool dijkstra(int maxEdge, long long k, int n){
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto[costSoFar, node] = pq.top();
            pq.pop();
            if(costSoFar > dist[node]){
                continue;
            }
            if(node == n-1){
                return costSoFar<=k;
            }
            for(auto &next:adjList[node]){
                int nextNode = next.first;
                int edge = next.second;
                if(edge < maxEdge){
                    continue;
                }
                long long nextCost = costSoFar+edge;
                if(nextCost > k){
                    continue;
                }
                if(nextCost < dist[nextNode]){
                    dist[nextNode] = nextCost;
                    pq.push({nextCost, nextNode});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int maxEdge = 0;
        for(vector<int> edge:edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            if(online[u] && online[v]){
                adjList[u].push_back({v, cost});
                maxEdge = max(maxEdge, cost);
            }
        }
        int ans = -1;
        int left = 0;
        int right = maxEdge;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(dijkstra(mid, k, n)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};