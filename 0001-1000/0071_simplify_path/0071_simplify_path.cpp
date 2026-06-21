class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int len = path.length();
        stack<string> st;
        for(int i=0; i<len; i++){
            if(path[i] == '/'){
                continue;
            }
            string temp = "";
            while(i<len && path[i]!='/'){
                temp = temp+path[i];
                i++;
            }
            if(temp == "."){
                continue;
            }else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
                continue;
            }else{
                st.push(temp);
            }
        }
        while(!st.empty()){
            ans = '/'+st.top()+ans;
            st.pop();
        }
        
        if(ans == ""){
            ans = '/';
        }
        return ans;
    }
};