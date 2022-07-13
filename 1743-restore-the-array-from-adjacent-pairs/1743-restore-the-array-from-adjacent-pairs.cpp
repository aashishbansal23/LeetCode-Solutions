class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int start;
        unordered_map<int, int> mp;
        for(auto i:adjacentPairs){
            mp[i[0]]++;
            mp[i[1]]++;
        }
        for(auto i:mp){
            if(i.second == 1){
                start = i.first;
            }
        }
        unordered_map<int, vector<int>> adj;
        for(auto i:adjacentPairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        set<int> visited;
        vector<int> ans;
        while(visited.count(start) == 0){
            ans.push_back(start);
            visited.insert(start);
            for(auto i:adj[start]){
                if(visited.count(i) == 0){
                    start = i;
                }
            }
        }
        return ans;
    }
};