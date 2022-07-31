class Solution {
    vector<int> getCount(string& word){
        vector<int> count(26, 0);
        for(auto ch:word){
            count[ch-'a']++;
        }
        return count;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26, 0);
        for(auto word:words2){
            vector<int> temp = getCount(word);
            for(int i=0; i<26; i++){
                count[i] = max(count[i], temp[i]);
            }
        }
        vector<string> ans;
        for(auto word:words1){
            vector<int> temp = getCount(word);
            int i = 0;
            for(i=0; i<26; i++){
                if(count[i] > temp[i]){
                    break;
                }
            }
            if(i == 26){
                ans.push_back(word);
            }
        }
        return ans;
    }
};