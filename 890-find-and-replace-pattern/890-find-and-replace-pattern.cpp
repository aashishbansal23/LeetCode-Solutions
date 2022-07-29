class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word:words){
            unordered_map<char, char> mp1, mp2;
            bool flag = true;
            for(int i=0; i<pattern.length(); i++){
                if(mp1.count(pattern[i]) > 0){
                    if(mp1[pattern[i]] != word[i]){
                        flag = false;
                        break;
                    }
                }else if(mp2.count(word[i]) > 0){
                    if(mp2[word[i]] != pattern[i]){
                        flag = false;
                        break;
                    }
                }else{
                    mp1[pattern[i]] = word[i];
                    mp2[word[i]] = pattern[i];
                }
            }
            if(flag){
                ans.push_back(word);
            }
        }
        return ans;
    }
};