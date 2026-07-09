class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                component[i] = component[i-1];
            }else{
                component[i] = i;
            }
        }
        vector<bool> ans(queries.size(), false);
        for(int i=0; i<queries.size(); i++){
            if(component[queries[i][0]] == component[queries[i][1]]){
                ans[i] = true;
            }
        }
        return ans;
    }
};