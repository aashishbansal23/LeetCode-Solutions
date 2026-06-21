class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allMask = (1<<n)-1;
        set<pair<int, int>> visited;
        queue<pair<int, pair<int, int>>> q;
        for(int i=0; i<n; i++){
            int mask = (1<<i);
            q.push({i, {0, mask}});
            visited.insert({i, mask});
        }
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int node = p.first;
            int dist = p.second.first;
            int mask = p.second.second;
            for(auto neighbour:graph[node]){
                int newMask = (mask | (1<<neighbour));
                if(newMask == allMask){
                    return 1+dist;
                }
                if(visited.count({neighbour, newMask}) == 0){
                    q.push({neighbour, {dist+1, newMask}});
                    visited.insert({neighbour, newMask});
                }
            }
        }
        return 0;
    }
};