class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size < 2){
            return size;
        }
        
        int ans = 1;
        sort(intervals.begin(), intervals.end());
        int curr0 = intervals[0][0];
        int curr1 = intervals[0][1];
        for(int i=1; i<size; i++){
            if(intervals[i][0]>curr0 && intervals[i][1]>curr1){
                ans++;
            }
            if(intervals[i][1] > curr1){
                curr0 = intervals[i][0];
                curr1 = intervals[i][1];
            }
        }
        return ans;
    }
};