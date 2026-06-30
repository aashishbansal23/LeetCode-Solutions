class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {};
        int count = 0;
        int i = 0;
        for(char ch:s){
            freq[ch-'a']++;
            while(freq[0] && freq[1] && freq[2]){
                freq[s[i++]-'a']--;
            }
            count += i;
        }
        return count;
    }
};