class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0].push_back("");
        dp[1].push_back("()");
        for(int i=2; i<n+1; i++){
            for(int j=0; j<i; j++){
                for(auto str:dp[j]){
                    string temp = "(" + str + ")";
                    for(auto str2:dp[i-j-1]){
                        string temp2 = temp+str2;
                        dp[i].push_back(temp2);
                    }
                }
            }
        }
        return dp[n];
    }
};