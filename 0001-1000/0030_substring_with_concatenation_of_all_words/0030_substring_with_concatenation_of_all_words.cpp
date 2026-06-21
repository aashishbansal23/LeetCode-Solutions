class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size();
        int m = words[0].length();
        if(s.length() < n*m){
            return ans;
        }
        for(int i=0; i<=s.length()-m*n; i++){
            unordered_map<string, int> mp;
            for(int j=0; j<n; j++){
                mp[words[j]]++;
            }
            int j;
            for(j=0; j<n; j++){
                string temp = s.substr(i+j*m, m);
                if(mp.count(temp)==0 || mp[temp]==0){
                    break;
                }else{
                    mp[temp]--;
                }
            }
            if(j == n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};