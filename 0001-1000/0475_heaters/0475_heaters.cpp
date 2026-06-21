class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;
        for(int i=0; i<houses.size(); i++){
            int j = lower_bound(heaters.begin(), heaters.end(), houses[i])-heaters.begin();
            int tempAns = INT_MAX;
            if(j > 0){
                tempAns = abs(houses[i]-heaters[j-1]);
            }
            if(j < heaters.size()){
                tempAns = min(tempAns, abs(houses[i]-heaters[j]));
            }
            if(j < heaters.size()-1){
                tempAns = min(tempAns, abs(houses[i]-heaters[j+1]));
            }
            ans = max(ans, tempAns);
        }
        return ans;
        
        
        
        
        
        // First Try Brute Force
        // sort(houses.begin(), houses.end());
        // sort(heaters.begin(), heaters.end());
        // int ans = INT_MIN;
        // for(int i=0; i<houses.size(); i++){
        //     int tempAns = INT_MAX;
        //     for(int j=0; j<heaters.size(); j++){
        //         tempAns = min(tempAns, abs(houses[i]-heaters[j]));
        //     }
        //     ans = max(ans, tempAns);
        // }
        // return ans;
    }
};