class Solution {
    int getLengthOfLCS(string s1, string s2){
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
    
public:
    int minDistance(string word1, string word2) {
        int lcs = getLengthOfLCS(word1, word2);
        return word1.length()+word2.length()-2*lcs;
        
        
        
        
        // First Try Brute Force
        // if(word1 == word2){
        //     return 0;
        // }
        // if(word1 == ""){
        //     return word2.length();
        // }
        // if(word2 == ""){
        //     return word1.length();
        // }
        // return 1+min(min(minDistance(word1.substr(1), word2), minDistance(word1, word2.substr(1))), min(minDistance(word1.substr(0, word1.length()-1), word2), minDistance(word1, word2.substr(0, word2.length()-1))));
    }
};