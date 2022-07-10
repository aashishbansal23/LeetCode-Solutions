// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> distance(n, INT_MAX);
	    distance[0] = 0;
	    for(int i=0; i<n-1; i++){
	        for(auto j:edges){
	            int u = j[0];
	            int v = j[1];
	            int w = j[2];
	            if(distance[u] == INT_MAX){
	                continue;
	            }
	            distance[v] = min(distance[v], distance[u]+w);
	        }
	    }
	    int ans = 0;
	    for(auto j:edges){
	        int u = j[0];
            int v = j[1];
            int w = j[2];
            if(distance[v] > distance[u]+w){
                ans = 1;
                break;
            }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends