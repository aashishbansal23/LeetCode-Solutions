class Solution {
public:
    string smallestSubsequence(string s) {
        int len = s.length();
        vector<int> map(26, 0);
        for(int i=0; i<len; i++){
            map[s[i]-'a']++;
        }
        
        vector<bool> visited(26, false);
        string ans = "";
        for(int i=0; i<len; i++){
            map[s[i]-'a']--;
            if(!visited[s[i]-'a']){
                while(ans.length()>0 && ans.back()>s[i] && map[ans.back()-'a']>0){
                    visited[ans.back()-'a'] = false;
                    ans.pop_back();
                }
                ans += s[i];
                visited[s[i]-'a'] = true;
            }
        }
        return ans;
    }
};