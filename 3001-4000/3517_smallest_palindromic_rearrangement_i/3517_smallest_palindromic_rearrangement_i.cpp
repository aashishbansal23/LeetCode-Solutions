class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<len/2; i++){
            freq[s[i]-'a']++;
        }
        int j = 0;
        for(int i=0; i<26; i++){
            while(freq[i] > 0){
                s[j] = 'a'+i;
                s[len-j-1] = s[j];
                freq[i]--;
                j++;
            }
        }
        return s;
    }
};