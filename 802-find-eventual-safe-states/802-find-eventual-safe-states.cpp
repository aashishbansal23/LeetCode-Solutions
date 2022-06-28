class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& status){
        if(status[node] != 0){
            return status[node]==2;
        }
        status[node] = 1;
        for(auto neighbour:graph[node]){
            if(status[neighbour] == 2){
                continue;
            }
            if(status[neighbour]==1){
                return false;
            }
            if(dfs(neighbour, graph, status) == false){
                return false;
            }
        }
        status[node] = 2;
        return true;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> status(n, 0);
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(dfs(i, graph, status)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};