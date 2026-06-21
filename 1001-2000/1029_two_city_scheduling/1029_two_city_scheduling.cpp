class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> difference;
        int size = costs.size();
        int ans = 0;
        for(int i=0; i<size; i++){
            ans += costs[i][0];
            difference.push_back(costs[i][1]-costs[i][0]);
        }
        sort(difference.begin(), difference.end());
        for(int i=0; i<size/2; i++){
            ans += difference[i];
        }
        return ans;
    }
};