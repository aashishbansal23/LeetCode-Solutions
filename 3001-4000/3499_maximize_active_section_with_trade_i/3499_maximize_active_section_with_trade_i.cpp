class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ones = 0;
        int maxSum = 0;
        int prevrun = -1;
        int i = 0;
        while(i < n){
            if(s[i] == '1'){
                ones++;
                i++;
            }else{
                int curr = 0;
                while(i<n && s[i]=='0'){
                    curr++;
                    i++;
                }
                if(prevrun > 0){
                    maxSum = max(maxSum, prevrun+curr);
                }
                prevrun = curr;
            }
        }
        return ones+maxSum;
    }
};