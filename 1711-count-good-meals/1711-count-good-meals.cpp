class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int size = deliciousness.size();
        unordered_map<int, int> mp;
        // for(int i=0; i<size; i++){
        //     mp[deliciousness[i]]++;
        // }
        int ans = 0;
        int mod = 1000000007;
        for(int i=0; i<size; i++){
            for(int j=1; j<=pow(2,21); j*=2){
                int temp = j-deliciousness[i];
                if(mp.count(temp) > 0){
                    ans += (mp[temp]%mod);
                    ans = (ans%mod);
                }
            }
            mp[deliciousness[i]]++;
        }
        return (ans%mod);
    }
};