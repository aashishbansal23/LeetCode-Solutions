class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto ch:s){
            if(mp.count(ch) > 0){
                pq.push({mp[ch], ch});
                mp.erase(ch);
            }
        }
        s = "";
        while(!pq.empty()){
            for(int i=0; i<pq.top().first; i++){
                s.push_back(pq.top().second);
            }
            pq.pop();
        }
        return s;
    }
};