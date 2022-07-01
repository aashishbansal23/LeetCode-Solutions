class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordCheck(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            pair<string, int> p = q.front();
            q.pop();
            string word = p.first;
            int depth = p.second;
            if(word == endWord){
                return depth;
            }
            for(int i=0; i<word.length(); i++){
                char ch = word[i];
                for(int j=0; j<26; j++){
                    word[i] = 'a'+j;
                    if(wordCheck.find(word) != wordCheck.end()){
                        q.push({word, depth+1});
                        wordCheck.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};