class Solution {
    void helper(string s, set<string>& st, string output){
        if(s.length() == 0){
            st.insert(output);
            return ;
        }
        if(s.length() == 1){
            st.insert(output);
            st.insert(output+s[0]);
            return ;
        }
        helper(s.substr(1), st, output);
        helper(s.substr(1), st, output+s[0]);
    }
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> index(26);
        for(int i=0; i<s.length(); i++){
            index[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        for(auto word:words){
            int temp = -1;
            bool flag = true;
            for(auto ch:word){
                auto it = upper_bound(index[ch-'a'].begin(), index[ch-'a'].end(), temp);
                if(it == index[ch-'a'].end()){
                    flag = false;
                    break;
                }else{
                    temp = *it;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
        
        
        
        
        // Second Try Gives TLE
        // int ans = 0;
        // for(auto word:words){
        //     int i=0, j=0;
        //     while(i<s.length() && j<word.length()){
        //         if(s[i] == word[j]){
        //             i++;
        //             j++;
        //         }else{
        //             i++;
        //         }
        //     }
        //     if(j == word.length()){
        //         ans++;
        //     }
        // }
        // return ans;
        
        
        
        
        // First Try Gives TLE
        // set<string> st;
        // string output = "";
        // helper(s, st, output);
        // int count = 0;
        // for(int i=0; i<words.size(); i++){
        //     if(st.count(words[i]) > 0){
        //         count++;
        //     }
        // }
        // return count;
    }
};