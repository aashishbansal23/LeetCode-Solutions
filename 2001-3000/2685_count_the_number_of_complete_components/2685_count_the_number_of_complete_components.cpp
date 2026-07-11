class Solution {
    int bfs(int n, vector<vector<int>> adjList, vector<bool> visited){
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                queue<int> q;
                int nodes = 1;
                int edges = 0;
                visited[i] = true;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int nd:adjList[node]){
                        edges++;
                        if(!visited[nd]){
                            nodes++;
                            q.push(nd);
                            visited[nd] = true;
                        }
                    }
                }
                if((nodes*(nodes-1)) == edges){
                    ans++;
                }
            }
        }
        return ans;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>());
        for(vector<int> edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return bfs(n, adjList, visited);
    }
};