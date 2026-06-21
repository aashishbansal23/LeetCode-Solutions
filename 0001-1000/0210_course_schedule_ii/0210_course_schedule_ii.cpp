class Solution {
    bool detectCycle(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                if(detectCycle(neighbour, adj, visited)){
                    return true;
                }
            }else{
                return true;
            }
        }
        visited[node] = false;
        return false;
    }
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans){
        visited[node] = true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited, ans);
            }
        }
        ans.push_back(node);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses, false);
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(detectCycle(i, adj, visited)){
                    return {};
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                dfs(i, adj, visited, ans);
            }
        }
        for(auto i:visited){
            if(!i){
                return {};
            }
        }
        return ans;
    }
};