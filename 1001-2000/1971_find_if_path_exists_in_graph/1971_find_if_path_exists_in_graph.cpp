class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination && source<n){
            return true;
        }
        vector<vector<int>> adjacentList(n);
        for(int i=0; i<edges.size(); i++){
            adjacentList[edges[i][0]].push_back(edges[i][1]);
            adjacentList[edges[i][1]].push_back(edges[i][0]);
        }
        set<int> visited;
        queue<int> q;
        q.push(source);
        visited.insert(source);
        bool ans = false;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(int i=0; i<adjacentList[currNode].size(); i++){
                if(adjacentList[currNode][i] == destination){
                    ans = true;
                    break;
                }
                if(visited.count(adjacentList[currNode][i]) == 0){
                    q.push(adjacentList[currNode][i]);
                    visited.insert(adjacentList[currNode][i]);
                }
            }
            if(ans){
                break;
            }
        }
        return ans;
    }
};