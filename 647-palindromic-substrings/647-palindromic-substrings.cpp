class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int len = s.length();
        for(int i=0; i<len; i++){
            int low = i;
            int high = i;
            while(low>=0 && high<len && s[low--]==s[high++]){
                ans++;
            }
            low = i-1;
            high = i;
            while(low>=0 && high<len && s[low--]==s[high++]){
                ans++;
            }
        }
        return ans;
    }
};