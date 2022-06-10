#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> frequency;
        int len = s.length();
        int start = 0;
        int end = 0;
        int ans = 0;
        while(end < len){
            frequency[s[end]]++;
            while(frequency[s[end]] != 1){
                frequency[s[start]]--;
                start++;
            }
            ans = max(ans, end-start+1);
            end++;
        }
        return ans;
        
        
        
        
        
        
        
        // First Try
        // int n = s.length();
        // if(n <= 1){
        //     return n;
        // }
        // int ans = 1;
        // for(int i=0; i<n-1; i++){
        //     set<char> st;
        //     int temp = 1;
        //     char ch = s[i];
        //     st.insert(ch);
        //     for(int j=i+1; j<n; j++){
        //         if(st.find(s[j]) != st.end()){
        //             break;
        //         }else{
        //             st.insert(s[j]);
        //             temp++;
        //         }
        //     }
        //     ans = max(ans, temp);
        // }
        // return ans;
    }
};