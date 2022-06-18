class TrieNode{
public:
    TrieNode* children[27] = {NULL};
    int index = -1;
};

class Trie{
    TrieNode* root = new TrieNode();
    
public:
    void insert(string& word, int& index){
        TrieNode* root = this->root;
        for(auto ch:word){
            if(root->children[ch-'a'] == NULL){
                root->children[ch-'a'] = new TrieNode();
            }
            root = root->children[ch-'a'];
            root->index = index;
        }
    }
    
    int search(string word){
        TrieNode* root = this->root;
        for(auto ch:word){
            if(root->children[ch-'a'] == NULL){
                return -1;
            }else{
                root = root->children[ch-'a'];
            }
        }
        return root->index;
    }
};

class WordFilter {
    Trie* dict = new Trie();
    
public:
    WordFilter(vector<string>& words) {
        int size = words.size();
        for(int i=0; i<size; i++){
            string word = words[i];
            int len = word.length();
            for(int j=0; j<len; j++){
                string temp = word.substr(j)+"{"+word;
                dict->insert(temp, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return dict->search(suffix+"{"+prefix);
    }
};


// Second Try
// class WordFilter {
//     unordered_map<string, int> stringToIndex;
    
// public:
//     WordFilter(vector<string>& words) {
//         int size = words.size();
//         for(int k=0; k<size; k++){
//             int len = words[k].length();
//             string word = words[k];
//             for(int i=len; i>0; i--){
//                 for(int j=0; j<len; j++){
//                     string temp = word.substr(0,i)+"-"+word.substr(j, len-j);
//                     stringToIndex[temp] = k;
//                 }
//             }
//         }
//     }
    
//     int f(string prefix, string suffix) {
//         if(stringToIndex.count(prefix+"-"+suffix) > 0){
//             return stringToIndex[prefix+"-"+suffix];
//         }else{
//             return -1;
//         }
//     }
// };




// First Try Gives TLE

// class TrieNode{
// public:
//     char data;
//     TrieNode* children[26] = {NULL};
//     vector<int> indexes;
//     TrieNode(char ch){
//         data = ch;
//     }
// };

// class Trie{
//     TrieNode* root = new TrieNode('0');
    
// public:
//     void insert(string& word, int& index){
//         TrieNode* root = this->root;
//         for(auto ch:word){
//             root->indexes.push_back(index);
//             // int i = ch-'a';
//             if(root->children[ch-'a'] == NULL){
//                 root->children[ch-'a'] = new TrieNode(ch);
//             }
//             root = root->children[ch-'a'];
//         }
//         root->indexes.push_back(index);
//     }
    
//     vector<int> getStartsWith(string& word){
//         TrieNode* root = this->root;
//         for(auto ch:word){
//             // int index = ch-'a';
//             if(root->children[ch-'a'] == NULL){
//                 return {};
//             }else{
//                 root = root->children[ch-'a'];
//             }
//         }
//         return root->indexes;
//     }
// };

// class WordFilter {
//     Trie* dictPre = new Trie();
//     Trie* dictSuff = new Trie();
    
// public:
//     WordFilter(vector<string>& words) {
//         int size = words.size();
//         for(int i=0; i<size; i++){
//             dictPre->insert(words[i], i);
//             reverse(words[i].begin(),words[i].end());
//             dictSuff->insert(words[i], i);
//         }
//     }
    
//     int f(string prefix, string suffix) {
//         vector<int> preAns = dictPre->getStartsWith(prefix);
//         reverse(suffix.begin(), suffix.end());
//         vector<int> suffAns = dictSuff->getStartsWith(suffix);
//         int i = preAns.size()-1;
//         int j = suffAns.size()-1;
//         while(i>=0 && j>=0){
//             if(preAns[i] == suffAns[j]){
//                 return preAns[i];
//             }else if(preAns[i] > suffAns[j]){
//                 i--;
//             }else{
//                 j--;
//             }
//         }
//         return -1;
//     }
// };

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */