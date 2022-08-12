class Solution {
    bool isMatchRecursion(string& s, int i, string& p, int j){
        if(i==0 && j==0){
            return true;
        }
        if(i>0 && j==0){
            return false;
        }
        if(i==0 && j>0){
            while(j > 0){
                if(p[j-1] != '*'){
                    return false;
                }
                j -= 2;
            }
            return true;
        }
        if(s[i-1]==p[j-1] || p[j-1]=='.'){
            return isMatchRecursion(s, i-1, p, j-1);
        }else if(p[j-1] == '*'){
            if(s[i-1]==p[j-2] || p[j-2]=='.'){
                return isMatchRecursion(s, i-1, p, j) || isMatchRecursion(s, i-1, p, j-2) || isMatchRecursion(s, i, p, j-2);
            }else{
                return isMatchRecursion(s, i, p, j-2);
            }
        }else{
            return false;
        }
    }
    
    bool isMatchMemoization(string& s, int i, string& p, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return true;
        }
        if(i>0 && j==0){
            return false;
        }
        if(i==0 && j>0){
            while(j > 0){
                if(p[j-1] != '*'){
                    return false;
                }
                j -= 2;
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i-1]==p[j-1] || p[j-1]=='.'){
            return dp[i][j]=isMatchMemoization(s, i-1, p, j-1, dp);
        }else if(p[j-1] == '*'){
            if(s[i-1]==p[j-2] || p[j-2]=='.'){
                return dp[i][j]=isMatchMemoization(s, i-1, p, j, dp) || isMatchMemoization(s, i-1, p, j-2, dp) || isMatchMemoization(s, i, p, j-2, dp);
            }else{
                return dp[i][j]=isMatchMemoization(s, i, p, j-2, dp);
            }
        }else{
            return dp[i][j]=false;
        }
    }
    
public:
    bool isMatch(string s, string p) {
        // Recursion
        return isMatchRecursion(s, s.length(), p, p.length());
        
        // Memoization
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        return isMatchMemoization(s, s.length(), p, p.length(), dp);
    }
};