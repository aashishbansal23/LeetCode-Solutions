class Solution {
    void dfs(int head, vector<vector<int>>& adj, vector<int>& informTime, int time, int& ans){
        for(auto neighbour:adj[head]){
            dfs(neighbour, adj, informTime, time+informTime[head], ans);
        }
        ans = max(ans, time);
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0; i<manager.size(); i++){
            if(manager[i] == -1){
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        int ans = 0;
        dfs(headID, adj, informTime, 0, ans);
        return ans;
    }
};