class Solution {
public:
    int numTrees(int n) {
        if(n < 2){
            return n;
        }
        vector<int> dp(n+1, 1);
        for(int i=2; i<=n; i++){
            int tempAns = 0;
            for(int j=1; j<=i; j++){
                tempAns += (dp[i-j]*dp[j-1]);
            }
            dp[i] = tempAns;
        }
        return dp[n];
    }
};