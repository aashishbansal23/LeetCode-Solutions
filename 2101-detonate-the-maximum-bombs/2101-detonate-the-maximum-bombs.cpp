class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                long long dist = (long long)(pow((bombs[i][0]-bombs[j][0]),2)) + (long long)(pow((bombs[i][1]-bombs[j][1]),2));
                if(dist <= (long long)(pow(bombs[i][2],2))){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            vector<bool> visited(n, false);
            int count = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            count++;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto j:adj[node]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                        count++;
                    }
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};