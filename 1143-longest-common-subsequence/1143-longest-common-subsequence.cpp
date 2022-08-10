class Solution {
    int longestCommonSubsequenceRecursion(string& text1, int index1, string& text2, int index2){
        if(index1==0 || index2==0){
            return 0;
        }
        int ans1 = longestCommonSubsequenceRecursion(text1, index1-1, text2, index2);
        int ans2 = longestCommonSubsequenceRecursion(text1, index1, text2, index2-1);
        int ans = max(ans1, ans2);
        if(text1[index1-1] == text2[index2-1]){
            ans = max(ans, longestCommonSubsequenceRecursion(text1, index1-1, text2, index2-1)+1);
        }
        return ans;
    }
    
    int longestCommonSubsequenceMemoization(string& text1, int index1, string& text2, int index2, vector<vector<int>>& dp){
        if(index1==0 || index2==0){
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        int ans1 = longestCommonSubsequenceMemoization(text1, index1-1, text2, index2, dp);
        int ans2 = longestCommonSubsequenceMemoization(text1, index1, text2, index2-1, dp);
        int ans = max(ans1, ans2);
        if(text1[index1-1] == text2[index2-1]){
            ans = max(ans, longestCommonSubsequenceMemoization(text1, index1-1, text2, index2-1, dp)+1);
        }
        return dp[index1][index2]=ans;
    }
    
    int longestCommonSubsequenceDP(string& text1, string& text2){
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        for(int i=1; i<text1.length()+1; i++){
            for(int j=1; j<text2.length()+1; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Recursion
        // return longestCommonSubsequenceRecursion(text1, text1.length(), text2, text2.length());
        
        // Memoization
        // vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        // dp[0][0] = 0;
        // for(int i=1; i<text1.length()+1; i++){
        //     dp[i][0] = 0;
        // }
        // for(int i=1; i<text2.length()+1; i++){
        //     dp[0][i] = 0;
        // }
        // return longestCommonSubsequenceMemoization(text1, text1.length(), text2, text2.length(), dp);
        
        // DP
        return longestCommonSubsequenceDP(text1, text2);
    }
};