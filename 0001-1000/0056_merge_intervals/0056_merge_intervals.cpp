class Solution {
    bool static compater(vector<int> v1, vector<int> v2){
        return (v1[0] < v2[0]);
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compater);
        vector<vector<int>> ans;
        int len = intervals.size();
        int first = intervals[0][0];
        int second = intervals[0][1];
        for(int i=1; i<len; i++){
            if(second >= intervals[i][0]){
                second = max(second, intervals[i][1]);
                first = min(first, intervals[i][0]);
            }else{
                ans.push_back({first, second});
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        if(ans.size()==0 || ans.back()[0]!=first){
            ans.push_back({first, second});
        }
        return ans;
    }
};