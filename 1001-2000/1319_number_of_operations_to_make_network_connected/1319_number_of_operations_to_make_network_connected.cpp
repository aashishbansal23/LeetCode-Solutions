class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited);
            }
        }
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(int i=0; i<edges; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                ans++;
            }
        }
        return ans-1;
    }
};