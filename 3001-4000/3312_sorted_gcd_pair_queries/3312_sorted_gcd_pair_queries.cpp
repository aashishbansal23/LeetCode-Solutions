class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int numsMax = 0;
        for(int num:nums){
            numsMax = max(numsMax, num);
        }
        vector<int> count(numsMax+1, 0);
        for(int num:nums){
            count[num]++;
        }
        vector<long long> gcdPairs(numsMax+1, 0);
        for(int i=1; i<=numsMax; i++){
            for(int j=i; j<=numsMax; j+=i){
                gcdPairs[i] += count[j];
            }
            gcdPairs[i] = (gcdPairs[i]*(gcdPairs[i]-1))/2;
        }
        for(int i=numsMax; i>=1; i--){
            for(int j=2*i; j<=numsMax; j+=i){
                gcdPairs[i] -= gcdPairs[j];
            }
        }
        for(int i=1; i<=numsMax; i++){
            gcdPairs[i] += gcdPairs[i-1];
        }
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            long long k = queries[i]+1;
            int left = 1;
            int right = numsMax;
            while(left < right){
                int mid = left+(right-left)/2;
                if(gcdPairs[mid] >= k){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }
            ans[i] = left;
        }
        return ans;
    }
};