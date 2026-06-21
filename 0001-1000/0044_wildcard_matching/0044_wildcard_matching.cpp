class Solution {
    bool isMatchRecursion(string& p, int i, string& s, int j){
        if(i==0 && j==0){
            return true;
        }
        if(i==0 && j>0){
            return false;
        }
        if(i>0 && j==0){
            while(i > 0){
                if(p[i-1] != '*'){
                    return false;
                }
                i--;
            }
            return true;
        }
        if(p[i-1]==s[j-1] || p[i-1]=='?'){
            return isMatchRecursion(p, i-1, s, j-1);
        }else if(p[i-1] == '*'){
            return isMatchRecursion(p, i, s, j-1) || isMatchRecursion(p, i-1, s, j);
        }else{
            return false;
        }
    }
    
    bool isMatchMemoization(string& p, int i, string& s, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return true;
        }
        if(i==0 && j>0){
            return false;
        }
        if(i>0 && j==0){
            while(i > 0){
                if(p[i-1] != '*'){
                    return false;
                }
                i--;
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[i-1]==s[j-1] || p[i-1]=='?'){
            return dp[i][j]=isMatchMemoization(p, i-1, s, j-1, dp);
        }else if(p[i-1] == '*'){
            return dp[i][j]=isMatchMemoization(p, i, s, j-1, dp) || isMatchMemoization(p, i-1, s, j, dp);
        }else{
            return dp[i][j]=false;
        }
    }
    
    bool isMatchDP(string& p,string& s){
        int m = p.length();
        int n = s.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=1; i<m+1; i++){
            bool flag = true;
            for(int j=1; j<=i; j++){
                if(p[j-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
    
public:
    bool isMatch(string s, string p) {
        // Recursion
        // return isMatchRecursion(p, p.length(), s, s.length());
        
        // Memoization
        // vector<vector<int>> dp(p.length()+1, vector<int>(s.length()+1, -1));
        // return isMatchMemoization(p, p.length(), s, s.length(), dp);
        
        // DP
        return isMatchDP(p, s);
    }
};