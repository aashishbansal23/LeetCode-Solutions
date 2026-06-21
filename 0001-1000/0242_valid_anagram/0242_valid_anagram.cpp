class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_s = s.length();
        int len_tt = t.length();
        if(len_s != len_tt){
            return false;
        }
        unordered_map<char, int> map_s, map_tt;
        for(int i=0; i<len_s; i++){
            map_s[s[i]]++;
            map_tt[t[i]]++;
        }
        if(map_s != map_tt){
            return false;
        }else{
            return true;
        }
    }
};