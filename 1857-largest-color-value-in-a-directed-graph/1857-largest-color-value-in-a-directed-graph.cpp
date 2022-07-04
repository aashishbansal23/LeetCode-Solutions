class Solution {
    void dfs(int node, vector<vector<int>>& adj, string& colors, int& n, vector<bool>& visited, unordered_map<char, int>& mp, int& ans){
        visited[node] = true;
        mp[colors[node]]++;
        bool flag = true;
        for(auto neighbour:adj[node]){
            flag = false;
            if(visited[neighbour]){
                ans = -1;
                return ;
            }
            dfs(neighbour, adj, colors, n, visited, mp, ans);
            if(ans == -1){
                return ;
            }
        }
        if(flag){
            for(auto i:mp){
                ans = max(ans, i.second);
            }
        }
        visited[node] = false;
        mp[colors[node]]--;
    }
    
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        vector<vector<int>> nodeColors(n, vector<int>(26, 0));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                nodeColors[i][colors[i]-'a']++;
            }
        }
        int visited = 0;
        int ans = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited++;
            ans = max(ans, *max_element(begin(nodeColors[node]), end(nodeColors[node])));
            for(auto neighbour:adj[node]){
                for(char ch='a'; ch<='z'; ch++){
                    nodeColors[neighbour][ch-'a'] = max(nodeColors[neighbour][ch-'a'], nodeColors[node][ch-'a']+(ch==colors[neighbour]));
                }
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(visited < n){
            return -1;
        }else{
            return ans;
        }
        
        
        
        
        // First Try Gives TLE
        // int n = colors.length();
        // vector<vector<int>> adj(n);
        // for(auto i:edges){
        //     adj[i[0]].push_back(i[1]);
        // }
        // vector<bool> visited(n, false);
        // int ans = 0;
        // unordered_map<char, int> mp;
        // for(int i=0; i<n; i++){
        //     dfs(i, adj, colors, n, visited, mp, ans);
        //     if(ans == -1){
        //         return -1;
        //     }
        // }
        // return ans;
    }
};