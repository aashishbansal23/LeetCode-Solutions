class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> visited(n, false);
        for(auto i:meetings){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // time,node
        vector<int> ans;
        pq.push({0,0});
        pq.push({0,firstPerson});
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node] = true;
            ans.push_back(node);
            for(auto n:adj[node]){
                if(!visited[n.first] && n.second>=time){
                    pq.push({n.second, n.first});
                }
            }
        }
        return ans;
    }
};