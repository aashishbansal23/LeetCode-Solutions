// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> weight(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        weight[0] = 0;
        parent[0] = -1;
        
        for(int i=0; i<V; i++){
            int minn = INT_MAX;
            int node = 0;
            for(int j=0; j<V; j++){
                if(!mst[j] && minn>weight[j]){
                    minn = weight[j];
                    node = j;
                }
            }
            mst[node] = true;
            for(auto neighbour:adj[node]){
                int nd = neighbour[0];
                int wt = neighbour[1];
                if(!mst[nd] && wt<weight[nd]){
                    weight[nd] = wt;
                    parent[nd] = node;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<V; i++){
            ans += weight[i];
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends