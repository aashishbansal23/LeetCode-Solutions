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
    
public:
    bool isMatch(string s, string p) {
        // Recursion
        return isMatchRecursion(s, s.length(), p, p.length());
    }
};