class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> frequency;
        for(auto ch:s){
            frequency[ch]++;
        }
        set<int> st;
        int ans = 0;
        for(auto i:frequency){
            while(i.second>0 && st.count(i.second)>0){
                i.second--;
                ans++;
            }
            st.insert(i.second);
        }
        return ans;
    }
};