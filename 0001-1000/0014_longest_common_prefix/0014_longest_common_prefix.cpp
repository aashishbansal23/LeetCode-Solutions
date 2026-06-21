#include<bits/stdc++.h>
using namespace std;
class Solution {
    unsigned long int limits(vector<string>& strs){
        unsigned long minn = INT_MAX;
        for(int i=0; i<strs.size(); i++){
            minn = min(minn, strs[i].length());
        }
        return minn;
    }
    
    bool check(vector<string>& strs, int i){
        for(int j=1; j<strs.size(); j++){
            if(strs[0][i] != strs[j][i]){
                return false;
            }
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs[0].size(); i++){
            char ch = strs[0][i];
            bool match = true;
            for(int j=1;j<strs.size(); j++){
                if(strs[j].size()<i || ch!=strs[j][i]){
                    match = false;
                    break;
                }
            }
            if(match == false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
        
        
        
        
        
        // First Try
        // unsigned long limit = limits(strs);
        // string ans = "";
        // for(unsigned long i=0; i<limit; i++){
        //     bool flag = check(strs, i);
        //     if(flag){
        //         ans += strs[0][i];
        //     }else{
        //         break;
        //     }
        // }
        // return ans;
    }
};