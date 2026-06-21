class TrieNode{
public:
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root = new TrieNode();
    
    void getReferenceStringHelp(TrieNode* root, string& output, string& ans){
        if(root->isTerminal){
            ans += output+"#";
        }
        for(char ch='a'; ch<='z'; ch++){
            if(root->children[ch-'a'] != NULL){
                output.push_back(ch);
                getReferenceStringHelp(root->children[ch-'a'], output, ans);
                output.pop_back();
            }
        }
    }
    
public:
    void insert(string word){
        TrieNode* currNode = root;
        for(auto ch:word){
            if(currNode->children[ch-'a'] == NULL){
                currNode->children[ch-'a'] = new TrieNode();
            }
            currNode = currNode->children[ch-'a'];
            if(currNode->isTerminal){
                currNode->isTerminal = false;
            }
        }
        currNode->isTerminal = true;
    }
    
    void getReferenceString(string& output, string& ans){
        getReferenceStringHelp(root, output, ans);
    }
};

bool compator(string s1, string s2){
    return s1.length()<s2.length();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), compator);
        Trie* dict = new Trie();
        for(auto word:words){
            reverse(word.begin(), word.end());
            dict->insert(word);
        }
        string ans = "";
        string output = "";
        dict->getReferenceString(output, ans);
        return ans.length();
    }
};