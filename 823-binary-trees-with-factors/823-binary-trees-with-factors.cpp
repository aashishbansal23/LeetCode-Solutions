class Solution {
    int mod = 1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, long long> mp;
        for(auto i:arr){
            mp[i] = 1;
        }
        for(int i=1; i<arr.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(arr[i]%arr[j] != 0 || mp.count(arr[i]/arr[j]) == 0){
                    continue;
                }
                mp[arr[i]] += ((mp[arr[j]] * mp[arr[i]/arr[j]])%mod);
                mp[arr[i]] %= mod;
            }
        }
        int ans = 0;
        for(auto i:mp){
            ans += i.second;
            ans %= mod;
        }
        return ans;
    }
};