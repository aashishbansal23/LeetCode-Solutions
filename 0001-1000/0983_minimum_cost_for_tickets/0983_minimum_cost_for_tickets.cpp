class Solution {
    void solve(vector<int>& days, vector<int>& costs, int cost, int day, int num, int& ans){
        if(num == days.size()){
            ans = min(ans, cost);
            return ;
        }
        if(days[num] <= day){
            solve(days, costs, cost, day, num+1, ans);
            return ;
        }
        for(int i=0; i<3; i++){
            if(i == 0){
                solve(days, costs, cost+costs[i], days[num], num+1, ans);
            }else if(i == 1){
                solve(days, costs, cost+costs[i], days[num]+6, num+1, ans);
            }else{
                solve(days, costs, cost+costs[i], days[num]+29, num+1, ans);
            }
        }
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int> daysSet(days.begin(), days.end());
        vector<int> dp(*max_element(days.begin(), days.end())+1, 0);
        for(int i=1; i<dp.size(); i++){
            if(daysSet.count(i) == 0){
                dp[i] = dp[i-1];
            }else{
                dp[i] = min(dp[i-1]+costs[0], min(dp[max(0,i-7)]+costs[1], dp[max(0,i-30)]+costs[2]));
            }
        }
        return dp.back();
        
        
        
        
        
        // Brute Force Recursion
        // int ans = INT_MAX;
        // for(int i=0; i<3; i++){
        //     if(i == 0){
        //         solve(days, costs, costs[i], days[0], 1, ans);
        //     }else if(i == 1){
        //         solve(days, costs, costs[i], days[0], 1, ans);
        //     }else{
        //         solve(days, costs, costs[i], days[0], 1, ans);
        //     }
        // }
        // return ans;
    }
};