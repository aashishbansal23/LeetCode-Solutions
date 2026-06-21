class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string lcs = "";
        int i=m, j=n;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                lcs.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i][j-1] > dp[i-1][j]){
                    lcs.push_back(str2[j-1]);
                    j--;
                }else{
                    lcs.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        while(i > 0){
            lcs.push_back(str1[i-1]);
            i--;
        }
        while(j > 0){
            lcs.push_back(str2[j-1]);
            j--;
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};