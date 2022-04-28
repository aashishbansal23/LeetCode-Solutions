class Solution {
public:
    string removeOccurrences(string s, string part) {
        // int s_len = s.length();
        // int p_len = part.length();
        // int i = 0;
        // int j = 0;
        bool flag = true;
        while(flag){
            int s_len = s.length();
            int p_len = part.length();
            int i = 0;
            int j = 0;
            bool inner_flag = true;
            for(j=0; j<=(s_len-p_len); j++){
                if(inner_flag && s.substr(j, p_len)==part){
                    j += p_len-1;
                    inner_flag = false;
                }else{
                    s[i++] = s[j];
                }
            }
            while(j < s_len){
                s[i++] = s[j++];
            }
            s = s.substr(0, i);
            if(i == j){
                flag = false;
            }
        }
        return s;
        // for(j=0; j<=(s_len-p_len); j++){
        //     if(s.substr(j, p_len) == part){
        //         j += p_len-1;
        //     }else{
        //         s[i++] = s[j];
        //     }
        // }
        // while(j < s_len){
        //     s[i++] = s[j++];
        // }
        // return s.substr(0, i);
    }
};