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
    
    int find(int i, vector<int>& parent){
        if(parent[i] == -1){
            return i;
        }
        return parent[i]=find(parent[i], parent);
    }
    
    void unionSet(int i, int j, vector<int>& parent, vector<int>& rank){
        int p1 = find(i, parent);
        int p2 = find(j, parent);
        if(p1 != p2){
            if(rank[p1] > rank[p2]){
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }else{
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, -1);
        vector<int> rank(n+1, 1);
        for(auto edge:edges){
            int p1 = find(edge[0], parent);
            int p2 = find(edge[1], parent);
            if(p1 == p2){
                return edge;
            }else{
                unionSet(edge[0], edge[1], parent, rank);
            }
        }
        return {};
        
        
        
        
        // First Try
        // int n = edges.size();
        // vector<vector<int>> adj(n+1);
        // vector<bool> visited(n+1, false);
        // for(auto edge:edges){
        //     if(visited[edge[0]] && visited[edge[1]]){
        //         vector<bool> tempVisited(n+1, false);
        //         if(dfs(adj, edge[0], edge[1], tempVisited)){
        //             return edge;
        //         }else{
        //             visited[edge[0]] = true;
        //             visited[edge[1]] = true;
        //             adj[edge[0]].push_back(edge[1]);
        //             adj[edge[1]].push_back(edge[0]);
        //         }
        //     }else{
        //         adj[edge[0]].push_back(edge[1]);
        //         adj[edge[1]].push_back(edge[0]);
        //         visited[edge[0]] = true;
        //         visited[edge[1]] = true;
        //     }
        // }
        // return {};
    }
};