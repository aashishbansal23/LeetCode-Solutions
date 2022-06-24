class Solution {
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited){
        if(visited[node]){
            return ;
        }
        visited[node] = true;
        for(auto neighbour:rooms[node]){
            dfs(neighbour, rooms, visited);
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        for(auto state:visited){
            if(!state){
                return false;
            }
        }
        return true;
    }
};