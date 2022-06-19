// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool isCycleHelp(int v, vector<int> adj[], unordered_map<int, bool>& visited){
        unordered_map<int, int> parent;
        parent[v] = -1;
        visited[v] = true;
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto neighbour:adj[currNode]){
                if(visited[neighbour] && neighbour!=parent[currNode]){
                    return true;
                }else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = currNode;
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> visited;
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleHelp(i, adj, visited)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends