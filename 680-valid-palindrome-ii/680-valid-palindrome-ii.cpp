class Solution {
    bool helper(string& s, int i, int j, int count){
        if(i >= j){
            return true;
        }
        bool temp1;
        if(s[i] != s[j]){
            if(count == 0){
                temp1 = false;
            }else{
                count--;
                temp1 = helper(s, i+1, j, count) || helper(s, i, j-1, count);
            }
        }else{
            temp1 = helper(s, i+1, j-1, count);
        }
        return temp1;
    }
    
public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.length()-1, 1);
    }
};