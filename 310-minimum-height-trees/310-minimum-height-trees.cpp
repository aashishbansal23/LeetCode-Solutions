class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0){
            return {};
        }else if(n == 1){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        while(!q.empty()){
            ans.clear();
            int size = q.size();
            while(size-- > 0){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto n:adj[node]){
                    degree[n]--;
                    if(degree[n] == 1){
                        q.push(n);
                    }
                }
            }
        }
        return ans;
    }
};