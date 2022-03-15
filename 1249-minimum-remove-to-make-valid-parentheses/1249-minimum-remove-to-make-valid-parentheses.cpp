class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        string ans = s;
        int open = 0;
        for(int i=0; i<len; i++){
            if(ans[i] == '('){
                open++;
            }else if(ans[i] == ')'){
                if(open == 0){
                    ans[i] = '*';
                }else{
                    open--;
                }
            }
        }
        open = 0;
        for(int i=len-1; i>=0; i--){
            if(ans[i] == ')'){
                open++;
            }else if(ans[i] == '('){
                if(open == 0){
                    ans[i] = '*';
                }else{
                    open--;
                }
            }
        }
        int k = 0;
        for(int i=0; i<len; i++){
            if(ans[i] != '*'){
                ans[k++] = ans[i];
            }
        }
        return ans.substr(0,k);
    }
};