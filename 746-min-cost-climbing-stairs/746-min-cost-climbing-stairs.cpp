class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one = cost[0];
        int two = cost[1];
        for(int i=2; i<cost.size(); i++){
            int temp = cost[i]+min(one, two);
            one = two;
            two = temp;
        }
        return min(one, two);
        
        
        
        
        
        
        // if(cost.size() == 1){
        //     return cost[cost.size()-1];
        // }
        // int ans[cost.size()+1];
        // ans[0] = cost[0];
        // ans[1] = cost[1];
        // for(int i=2; i<cost.size()+1; i++){
        //     if(i==cost.size()){
        //         ans[i] = min(ans[i-1],ans[i-2]);
        //     }else{
        //         ans[i] = cost[i]+min(ans[i-1],ans[i-2]);
        //     }
        // }
        // return min(ans[cost.size()-1], ans[cost.size()]);
    }
};