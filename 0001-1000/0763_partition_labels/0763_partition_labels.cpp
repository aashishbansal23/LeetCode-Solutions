class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.length();
        unordered_map<char, int> mp;
        for(int i=0; i<len; i++){
            mp[s[i]] = i;
        }
        vector<int> ans;
        int temp = -1;
        int pre = -1;
        for(int i=0; i<len; i++){
            if(temp == -1){
                temp = mp[s[i]];
            }
            if(i == temp){
                ans.push_back(temp-pre);
                pre = temp;
                temp = -1;
                continue;
            }
            if(mp[s[i]] > temp){
                temp = mp[s[i]];
            }
        }
        return ans;
    }
};