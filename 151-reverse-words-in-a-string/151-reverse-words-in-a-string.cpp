class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int i = 0;
        while(i < len){
            int i_temp = i;
            while(i_temp<len && s[i_temp]!=' '){
                i_temp++;
            }
            reverse(s.begin()+i, s.begin()+i_temp);
            i = i_temp+1;
        }
        reverse(s.begin(), s.end());
        i = 0;
        int j = 0;
        while(j < len){
            while(j<len && s[j]==' '){
                j++;
            }
            while(j<len && s[j]!=' '){
                s[i++] = s[j++];
            }
            if(j < len){
                s[i++] = ' ';
            }
        }
        if(s.substr(0, i).back() == ' '){
            return s.substr(0, i-1);
        }else{
            return s.substr(0, i);
        }
    }
};