class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<size; i++){
            mp[nums[i]]++;
        }
        pair<int, int> p;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int len = 0;
        for(auto itr:mp){
            p = make_pair(itr.second, itr.first);
            if(len < k){
                pq.push(p);
                len++;
            }else if(pq.top().first < p.first){
                pq.pop();
                pq.push(p);
            }
        }
        
        len = 0;
        vector<int> ans;
        while(len < k){
            ans.push_back(pq.top().second);
            pq.pop();
            len++;
        }
        return ans;
        
        
        
        
        
        
//         unordered_map<int, int> mp;
//         int size = nums.size();
//         for(int i=0; i<size; i++){
//             mp[nums[i]]++;
//         }
        
//         unordered_map<int, int> :: iterator itr;
//         priority_queue<pair<int, int>> pq;
//         for(itr=mp.begin(); itr!=mp.end(); itr++){
//             pq.push(make_pair(itr->second, itr->first));
//         }
        
//         vector<int> ans;
//         int i = 0;
//         while(i < k){
//             ans.push_back(pq.top().second);
//             pq.pop();
//             i++;
//         }
//         return ans;
    }
};