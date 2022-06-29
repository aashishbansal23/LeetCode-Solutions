class Solution {
    void dfs(int node, vector<vector<int>>& adj, set<pair<int, int>>& st, vector<bool>& visited, int& ans){
        visited[node] = true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                if(st.count({node, neighbour}) > 0){
                    ans++;
                }
                dfs(neighbour, adj, st, visited, ans);
            }
        }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int, int>> st;
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            st.insert({i[0], i[1]});
        }
        vector<bool> visited(n, false);
        int ans = 0;
        dfs(0, adj, st, visited, ans);
        return ans;
    }
};