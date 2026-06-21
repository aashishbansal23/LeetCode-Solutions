class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        int size = points.size();
        for(int i=0; i<size-1; i++){
            unordered_map<double, int> mp;
            for(int j=i+1; j<size; j++){
                if(points[i][0] == points[j][0]){
                    mp[-5000]++;
                }else{
                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    mp[slope]++;
                }
            }
            int temp = 0;
            for(auto it:mp){
                temp = max(temp, it.second+1);
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};