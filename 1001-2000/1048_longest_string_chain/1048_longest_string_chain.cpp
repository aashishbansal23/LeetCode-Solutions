class Solution {
    bool static compator(string s1, string s2){
        return s1.length()<s2.length();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), compator);
        int size = words.size();
        int ans = 0;
        for(int i=0; i<size; i++){
            int currAns = 0;
            for(int j=0; j<words[i].length(); j++){
                string temp = words[i].substr(0, j)+words[i].substr(j+1, words[i].length()+1);
                currAns = max(currAns, mp[temp]+1);
            }
            mp[words[i]] = currAns;
            ans = max(ans, currAns);
        }
        return ans;
    }
};