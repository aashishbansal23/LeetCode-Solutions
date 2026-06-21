class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root = new TrieNode();
    
    void insertHelp(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertHelp(child, word.substr(1));
    }
    
    bool searchHelp(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0]-'a';
        if(root->children[index] != NULL){
            return searchHelp(root->children[index], word.substr(1));
        }else{
            return false;
        }
    }
    
    bool startsWithHelp(TrieNode* root, string word){
        if(word.length() == 0){
            return true;
        }
        int index = word[0]-'a';
        if(root->children[index] != NULL){
            return startsWithHelp(root->children[index], word.substr(1));
        }else{
            return false;
        }
    }
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        insertHelp(root, word);
    }
    
    bool search(string word) {
        return searchHelp(root, word);
    }
    
    bool startsWith(string prefix) {
        return startsWithHelp(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */