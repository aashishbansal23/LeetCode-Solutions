class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(int i=0; i<patterns.size(); i++){
            int len = patterns[i].length();
            int size = word.length();
            while(size>=len){
                if(word.substr(word.length()-size, len) == patterns[i]){
                    ans++;
                    break;
                }
                size--;
            }
        }
        return ans;
    }
};