class Solution {
    void dfs(string node, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& ans){
        while(!adj[node].empty()){
            string neighbour = adj[node].top();
            adj[node].pop();
            dfs(neighbour, adj, ans);
        }
        ans.push_back(node);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), [](vector<string> v1, vector<string> v2){return v1[1]<v2[1];});
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto ticket:tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};