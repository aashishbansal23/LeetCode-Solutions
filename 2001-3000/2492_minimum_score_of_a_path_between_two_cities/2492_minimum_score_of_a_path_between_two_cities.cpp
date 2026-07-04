class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto &road:roads){
            adjList[road[0]].push_back({road[1], road[2]});
            adjList[road[1]].push_back({road[0], road[2]});
        }
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int ans = INT_MAX;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto list:adjList[currNode]){
                int nextNode = list.first;
                int dist = list.second;
                ans = min(ans, dist);
                if(!visited[nextNode]){
                    q.push(nextNode);
                    visited[nextNode] = true;
                }
            }
        }
        return ans;
    }
};