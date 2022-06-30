class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0){
            return 0;
        }
        set<int> forbiddenSet(forbidden.begin(), forbidden.end());
        set<pair<int, bool>> visited;
        int ans = 0;
        queue<pair<int,bool>> q;
        q.push({0, true});
        q.push({0, false});
        // True-Forward
        // False-Backward
        visited.insert({0, true});
        visited.insert({0, false});
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto front = q.front();
                int val = front.first;
                bool flag = front.second;
                q.pop();
                if(val == x){
                    return ans;
                }
                if(val+a<=7000 && forbiddenSet.count(val+a)==0 && visited.count({val+a, true})==0){
                    q.push({val+a, true});
                    visited.insert({val+a, true});
                }
                if(flag && val-b>=0 && forbiddenSet.count(val-b)==0 && visited.count({val-b, false})==0){
                    q.push({val-b, false});
                    visited.insert({val-b, false});
                }
            }
            ans++;
        }
        return -1;
    }
};