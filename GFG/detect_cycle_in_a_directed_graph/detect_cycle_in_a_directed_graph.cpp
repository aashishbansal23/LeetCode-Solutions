// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool dfs(int v, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, vector<int> adj[]){
        visited[v] = true;
        dfsVisited[v] = true;
        for(auto neighbour:adj[v]){
            if(!visited[neighbour]){
                if(dfs(neighbour, visited, dfsVisited, adj)){
                    return true;
                }
            }else if(visited[neighbour] && dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[v] = false;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        for(int i=0; i<V; i++){
            if(dfs(i, visited, dfsVisited, adj)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends