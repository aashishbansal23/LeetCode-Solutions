class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> mp;
        for(auto point:points){
            mp[point[0]].insert(point[1]);
        }
        int ans = INT_MAX;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                if(points[i][0]==points[j][0] || points[i][1]==points[j][1]){
                    continue;
                }
                if(mp[points[i][0]].count(points[j][1])>0 && mp[points[j][0]].count(points[i][1])>0){
                    ans = min(ans, abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                }
            }
        }
        if(ans == INT_MAX){
            return 0;
        }else{
            return ans;
        }
    }
};