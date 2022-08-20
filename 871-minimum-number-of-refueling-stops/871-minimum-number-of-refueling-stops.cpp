class Solution {
    void minRefuelStopsRecursion(int current, int target, int fuel, vector<vector<int>>& stations, int i, int count, int& ans){
        if(i == stations.size()){
            if(current==target || current+fuel>=target){
                ans = min(ans, count);
            }
            return ;
        }
        if(current+fuel >= stations[i][0]){
            minRefuelStopsRecursion(stations[i][0], target, fuel-(stations[i][0]-current), stations, i+1, count, ans);
            minRefuelStopsRecursion(stations[i][0], target, fuel-(stations[i][0]-current)+stations[i][1], stations, i+1, count+1, ans);
        }
    }
    
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Recursion
        // if(stations.size() == 0){
        //     if(target == startFuel){
        //         return 0;
        //     }else{
        //         return -1;
        //     }
        // }
        // int ans = INT_MAX;
        // minRefuelStopsRecursion(0, target, startFuel, stations, 0, 0, ans);
        // if(ans == INT_MAX){
        //     return -1;
        // }else{
        //     return ans;
        // }
        
        
        
        int size = stations.size();
        vector<long long> dp(size+1, startFuel);
        for(int i=0; i<size; i++){
            for(int j=i; j>=0 && dp[j]>=stations[i][0]; j--){
                dp[j+1] = max(dp[j+1], dp[j]+stations[i][1]);
            }
        }
        for(int i=0; i<=size; i++){
            if(dp[i] >= target){
                return i;
            }
        }
        return -1;
    }
};