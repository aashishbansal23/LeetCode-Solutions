class Solution {
    bool isPalindrome(string s, int st, int ed){
        while(st < ed){
            if(s[st] != s[ed]){
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
    
    void helper(string s, int st, int ed, string& ans){
        if(st > ed){
            return ;
        }
        if(isPalindrome(s, st, ed)){
            string temp = s.substr(st, ed-st+1);
            if(temp.length() > ans.length()){
                ans = temp;
            }
        }
        helper(s, st, ed-1, ans);
        helper(s, st+1, ed, ans);
    }
    
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int start = 0;
        int maxLen = 1;
        for(int i=1; i<len; i++){
            int left = i-1;
            int right = i;
            while(left>=0 && right<len && s[left]==s[right]){
                if(right-left+1 > maxLen){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
            left = i-1;
            right = i+1;
            while(left>=0 && right<len && s[left]==s[right]){
                if(right-left+1 > maxLen){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLen);
        
        
        
        
        // First Try Brute Force Gives TLE
        // if(s.length() <= 1){
        //     return s;
        // }
        // string ans = "";
        // helper(s, 0, s.length()-1, ans);
        // return ans;
    }
};