class Solution {
public:
    string removeDuplicates(string s, int k) {
        int len = s.length();
        if(k > len){
            return s;
        }
        stack<pair<char, int>> st;
        for(int i=len-1; i>=0; i--){
            if(st.empty() || st.top().first!=s[i]){
                st.push(make_pair(s[i], 1));
            }else{
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top().first;
            int num = st.top().second;
            st.pop();
            for(int i=0; i<num; i++){
                ans += ch;
            }
        }
        return ans;
        
        
        
        
        // First Try gives TLE
        // int len = s.length();
        // if(k > len){
        //     return s;
        // }
        // stack<char> st;
        // for(int i=len-1; i>=0; i--){
        //     st.push(s[i]);
        // }
        // string ans = "";
        // while(!st.empty()){
        //     int i = 0;
        //     string temp = "";
        //     while(!st.empty() && i<k){
        //         if(temp.empty()){
        //             temp += st.top();
        //         }else if(temp.back() == st.top()){
        //             temp += st.top();
        //         }else{
        //             ans += temp;
        //             temp = "";
        //             break;
        //         }
        //         st.pop();
        //         i++;
        //     }
        //     if(i == k){
        //         for(int j=ans.length()-1; j>=0; j--){
        //             st.push(ans[j]);
        //         }
        //         ans = "";
        //     }else if(temp != ""){
        //         ans += temp;
        //     }
        // }
        // return ans;
    }
};