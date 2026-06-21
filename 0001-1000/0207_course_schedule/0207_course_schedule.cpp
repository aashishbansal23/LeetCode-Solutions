class Solution {
    bool dfs(int v, unordered_map<int, bool>& visited, unordered_map<int, bool> dfsVisited, vector<vector<int>>& adj){
        visited[v] = true;
        dfsVisited[v] = true;
        for(auto neighbour:adj[v]){
            if(!visited[neighbour] && dfs(neighbour, visited, dfsVisited, adj)){
                return true;
            }else if(visited[neighbour] && dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[v] = false;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        for(int i=0; i<numCourses; i++){
            if(!visited[i] && dfs(i, visited, dfsVisited, adj)){
                return false;
            }
        }
        return true;
    }
};