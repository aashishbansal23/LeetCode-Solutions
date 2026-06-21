class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int start = 0;
        int size = fruits.size();
        int ans = 0;
        for(int i=0; i<size; i++){
            mp[fruits[i]]++;
            if(mp.size() <= 2){
                ans = max(ans, i-start+1);
            }else{
                while(mp.size()>2 && start<=i){
                    mp[fruits[start]]--;
                    if(mp[fruits[start]] == 0){
                        mp.erase(fruits[start]);
                    }
                    start++;
                }
            }
        }
        return ans;
    }
};