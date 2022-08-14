class Solution {
    bool isScrambleRecursion(string s1, string s2){
        if(s1 == s2){
            return true;
        }
        int n1 = s1.length();
        if(n1 <= 1){
            return false;
        }
        for(int i=1; i<n1; i++){
            bool cond1 = isScrambleRecursion(s1.substr(0,i), s2.substr(n1-i,i)) && isScrambleRecursion(s1.substr(i,n1-i), s2.substr(0,n1-i));
            if(cond1){
                return true;
            }
            bool cond2 = isScrambleRecursion(s1.substr(0,i), s2.substr(0,i)) && isScrambleRecursion(s1.substr(i,n1-i), s2.substr(i,n1-i));
            if(cond2){
                return true;
            }
        }
        return false;
    }
    
    bool isScrambleMemoization(string s1, string s2, unordered_map<string, bool>& dp){
        if(s1 == s2){
            return true;
        }
        int n1 = s1.length();
        if(n1 <= 1){
            return false;
        }
        string temp = s1;
        temp.push_back(' ');
        temp.append(s2);
        if(dp.count(temp) > 0){
            return dp[temp];
        }
        for(int i=1; i<n1; i++){
            bool cond1 = isScrambleMemoization(s1.substr(0,i), s2.substr(n1-i,i), dp) && isScrambleMemoization(s1.substr(i,n1-i), s2.substr(0,n1-i), dp);
            if(cond1){
                return dp[temp]=true;
            }
            bool cond2 = isScrambleMemoization(s1.substr(0,i), s2.substr(0,i), dp) && isScrambleMemoization(s1.substr(i,n1-i), s2.substr(i,n1-i), dp);
            if(cond2){
                return dp[temp]=true;
            }
        }
        return dp[temp]=false;
    }
    
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()){
            return false;
        }
        if(s1=="" && s2==""){
            return true;
        }
        
        // Recursion
        // return isScrambleRecursion(s1, s2);
        
        // Memoization
        unordered_map<string, bool> dp;
        dp.clear();
        return isScrambleMemoization(s1, s2, dp);
    }
};