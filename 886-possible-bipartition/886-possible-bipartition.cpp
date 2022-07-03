class Solution {
    bool biparite(int node, vector<vector<int>>& adj, vector<int>& color){
        int currentColor = -1;
        queue<int> q;
        q.push(node);
        color[node] = currentColor;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto neighbour:adj[currNode]){
                if(color[neighbour] == 0){
                    q.push(neighbour);
                    color[neighbour] = -1*color[currNode];
                }else if(color[neighbour] == color[currNode]){
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> color(n+1, 0);
        for(int i=1; i<=n; i++){
            if(color[i] == 0){
                if(!biparite(i, adj, color)){
                    return false;
                }
            }
        }
        return true;
    }
};