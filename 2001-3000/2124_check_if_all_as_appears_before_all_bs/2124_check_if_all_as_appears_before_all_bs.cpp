class Solution {
public:
    bool checkString(string s) {
        int len = s.length();
        int i = 0;
        while(s[i] == 'a'){
            i++;
        }
        while(s[i] == 'b'){
            i++;
        }
        if(i != len){
            return false;
        }else{
            return true;
        }
    }
};