class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int size = arr.size();
        unordered_map<int, long> mp;
        for(int i=0; i<size; i++){
            mp[arr[i]]++;
        }
        
        int ans = 0;
        for(auto itr1:mp){
            for(auto itr2:mp){
                int i = itr1.first;
                int j = itr2.first;
                int k = target-i-j;
                if(!mp.count(k)){
                    continue;
                }
                if(i==j && j==k){
                    ans += ((mp[i]*(mp[i]-1)*(mp[i]-2)/6)%1000000007);
                }else if(i==j && j!=k){
                    ans += ((mp[i]*(mp[i]-1)/2*mp[k])%1000000007);
                }else if(i<j && j<k){
                    ans += ((mp[i]*mp[j]*mp[k])%1000000007);
                }
                
            }
        }
        ans = (ans%1000000007);
        return ans;
        
        
        
        
        
        
        
        
        // int size = arr.size();
        // int mod = 1000000007;
        // int ans = 0;
        // unordered_map<int, int> mp;
        // for(int i=0; i<size; i++){
        //     ans = (ans+mp[target-arr[i]])%mod;
        //     for(int j=0; j<i; j++){
        //         mp[arr[i]+arr[j]]++;
        //     }
        // }
        // return ans;
    }
};