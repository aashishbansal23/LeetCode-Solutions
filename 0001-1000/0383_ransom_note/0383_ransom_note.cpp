class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto ch:magazine){
            mp[ch]++;
        }
        for(auto ch:ransomNote){
            if(mp[ch] > 0){
                mp[ch]--;
            }else{
                return false;
            }
        }
        return true;
        
        
        
        
        // First Try
        // sort(ransomNote.begin(), ransomNote.end());
        // sort(magazine.begin(), magazine.end());
        // int i=0, j=0;
        // while(i<ransomNote.length() && j<magazine.length()){
        //     if(ransomNote[i] == magazine[j]){
        //         i++;
        //         j++;
        //     }else if(ransomNote[i] > magazine[j]){
        //         j++;
        //     }else{
        //         return false;
        //     }
        // }
        // if(i == ransomNote.length()){
        //     return true;
        // }else{
        //     return false;
        // }
    }
};