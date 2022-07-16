class Solution {
    bool solve(vector<int>& stones, set<int>& stonesSet, int element, int lastJump){
        if(stones.back() == element){
            return true;
        }
        if(stonesSet.count(element+lastJump-1)>0 && lastJump-1>0 && solve(stones, stonesSet, element+lastJump-1, lastJump-1)){
            return true;
        }else if(stonesSet.count(element+lastJump)>0 && solve(stones, stonesSet, element+lastJump, lastJump)){
            return true;
        }else if(stonesSet.count(element+lastJump+1)>0 && solve(stones, stonesSet, element+lastJump+1, lastJump+1)){
            return true;
        }else{
            return false;
        }
    }
    
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1){
            return false;
        }
        if(stones.size() == 2){
            return true;
        }
        unordered_map<int, set<int>> mp;
        for(auto i:stones){
            mp[i] = {};
        }
        mp[0].insert(0);
        mp[1].insert(1);
        for(int i=1; i<stones.size(); i++){
            for(auto j:mp[stones[i]]){
                if(j-1>0 && mp.count(stones[i]+j-1)>0){
                    mp[stones[i]+j-1].insert(j-1);
                }
                if(mp.count(stones[i]+j) > 0){
                    mp[stones[i]+j].insert(j);
                }
                if(mp.count(stones[i]+j+1) > 0){
                    mp[stones[i]+j+1].insert(j+1);
                }
            }
        }
        return mp[stones.back()].size()>0;
        
        
        
        
        // First Try Brute Force
        // if(stones[1] != 1){
        //     return false;
        // }
        // set<int> stonesSet(stones.begin(), stones.end());
        // return solve(stones, stonesSet, 1, 1);
    }
};