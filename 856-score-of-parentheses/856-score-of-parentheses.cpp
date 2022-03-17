class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int len = s.length();
        char pre = '(';
        int depth = 0;
        for(int i=0; i<len; i++){
            if(s[i] == '('){
                depth++;
            }else{
                depth--;
                if(pre == '('){
                    ans += pow(2, depth);
                }
            }
            pre = s[i];
        }
        return ans;
    }
};