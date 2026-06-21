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
    public:
    void insert(string word){
        TrieNode* currNode = root;
        for(auto ch:word){
            if(currNode->children[ch-'a'] == NULL){
                currNode->children[ch-'a'] = new TrieNode();
            }
            currNode = currNode->children[ch-'a'];
        }
        currNode->isTerminal = true;
    }
    
    void getSuggestions(TrieNode* currNode, vector<string>& output, string temp){
        if(currNode->isTerminal && output.size()<3){
            output.push_back(temp);
        }
        if(output.size() == 3){
            return ;
        }
        
        for(char ch='a'; ch<='z'; ch++){
            TrieNode* nextNode = currNode->children[ch-'a'];
            if(nextNode != NULL){
                temp.push_back(ch);
                getSuggestions(nextNode, output, temp);
                if(output.size() == 3){
                    return ;
                }
                temp.pop_back();
            }
        }
    }
    
    void checkPrefix(string word, vector<string>& output, vector<vector<string>>& ans){
        TrieNode* prev = root;
        string temp = "";
        int len = word.length();
        for(int i=0; i<len; i++){
            char ch = word[i];
            temp.push_back(ch);
            TrieNode* currNode = prev->children[ch-'a'];
            if(currNode == NULL){
                for(int j=i; j<len; j++){
                    ans.push_back(output);
                }
                break;
            }
            getSuggestions(currNode, output, temp);
            ans.push_back(output);
            output.clear();
            prev = currNode;
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* dict = new Trie;
        for(auto str:products){
            dict->insert(str);
        }
        vector<vector<string>> ans;
        vector<string> output;
        dict->checkPrefix(searchWord, output, ans);
        return ans;
    }
};