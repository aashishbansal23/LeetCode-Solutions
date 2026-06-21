class Solution {
    void dfs(vector<int>& candidates, int i, int target, vector<int>& output, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(output);
            return ;
        }
        if(target<0 || i>=candidates.size()){
            return ;
        }
        output.push_back(candidates[i]);
        dfs(candidates, i+1, target-candidates[i], output, ans);
        output.pop_back();
        int num = candidates[i];
        while(i<candidates.size() && candidates[i]==num){
            i++;
        }
        dfs(candidates, i, target, output, ans);
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        dfs(candidates, 0, target, output, ans);
        return ans;
    }
};