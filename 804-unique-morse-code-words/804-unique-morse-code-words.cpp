class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> morseCodes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        for(auto word:words){
            string temp = "";
            for(auto ch:word){
                temp.append(morseCodes[ch-'a']);
            }
            st.insert(temp);
        }
        return st.size();
    }
};