class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& output, vector<vector<int>>& ans){
        output.push_back(node);
        if(node == graph.size()-1){
            ans.push_back(output);
            output.pop_back();
            return ;
        }
        visited[node] = true;
        for(auto neighbour:graph[node]){
            if(!visited[neighbour]){
                dfs(neighbour, graph, visited, output, ans);
            }
        }
        output.pop_back();
        visited[node] = false;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<bool> visited(graph.size(), false);
        dfs(0, graph, visited, output, ans);
        return ans;
    }
};