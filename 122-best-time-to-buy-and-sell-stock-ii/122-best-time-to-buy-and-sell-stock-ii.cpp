class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minPrice = INT_MAX;
        int size = prices.size();
        for(int i=0; i<size; i++){
            minPrice = min(minPrice, prices[i]);
            if(minPrice < prices[i]){
                ans += prices[i]-minPrice;
                minPrice = prices[i];
            }
        }
        return ans;
    }
};