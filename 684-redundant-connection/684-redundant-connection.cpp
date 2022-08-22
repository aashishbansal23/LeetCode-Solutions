class Solution {
    bool dfs(vector<vector<int>>& adj, int source, int destination, vector<bool>& visited){
        if(source == destination){
            return true;
        }
        visited[source] = true;
        for(auto neighbour:adj[source]){
            if(!visited[neighbour]){
                if(dfs(adj, neighbour, destination, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        vector<bool> visited(n+1, false);
        for(auto edge:edges){
            if(visited[edge[0]] && visited[edge[1]]){
                vector<bool> tempVisited(n+1, false);
                if(dfs(adj, edge[0], edge[1], tempVisited)){
                    return edge;
                }else{
                    visited[edge[0]] = true;
                    visited[edge[1]] = true;
                    adj[edge[0]].push_back(edge[1]);
                    adj[edge[1]].push_back(edge[0]);
                }
            }else{
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
                visited[edge[0]] = true;
                visited[edge[1]] = true;
            }
        }
        return {};
    }
};