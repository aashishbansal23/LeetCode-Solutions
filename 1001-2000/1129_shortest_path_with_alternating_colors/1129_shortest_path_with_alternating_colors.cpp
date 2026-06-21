class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 0--Red
        // 1--Blue
        vector<vector<pair<int, int>>> adj(n);
        for(auto i:redEdges){
            adj[i[0]].push_back({i[1], 0});
        }
        for(auto i:blueEdges){
            adj[i[0]].push_back({i[1], 1});
        }
        vector<vector<int>> cost(n, vector<int>(2,-1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        cost[0][0] = 0;
        cost[0][1] = 0;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int color = p.second;
            for(auto neighbour:adj[node]){
                if(cost[neighbour.first][neighbour.second]!=-1 || color==neighbour.second){
                    continue;
                }
                cost[neighbour.first][neighbour.second] = cost[node][color]+1;
                q.push({neighbour.first, neighbour.second});
            }
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(min(cost[i][0], cost[i][1]) == -1){
                ans[i] = max(cost[i][0], cost[i][1]);
            }else{
                ans[i] = min(cost[i][0], cost[i][1]);
            }
        }
        return ans;
    }
};