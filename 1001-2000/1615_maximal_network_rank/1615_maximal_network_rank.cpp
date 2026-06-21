class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int edges = roads.size();
        vector<int> degree(n, 0);
        unordered_map<int, set<int>> mp;
        for(int i=0; i<edges; i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
            mp[roads[i][0]].insert(roads[i][1]);
            mp[roads[i][1]].insert(roads[i][0]);
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int temp = degree[i]+degree[j];
                if(mp.count(i)>0 && mp[i].count(j)>0){
                    temp--;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};