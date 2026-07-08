class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        int m = s.length();
        vector<int> ans(queries.size());
        vector<long long> preSum(m+1, 0);
        vector<long long> conVal(m+1, 0);
        vector<long long> count(m+1, 0);
        vector<long long> pow10(m+1, 0);
        for(int i=1; i<=m; i++){
            int num = s[i-1]-'0';
            preSum[i] = (preSum[i-1]+num)%mod;
            if(num == 0){
                conVal[i] = conVal[i-1];
                count[i] = count[i-1];
            }else{
                conVal[i] = (conVal[i-1]*10+num)%mod;
                count[i] = count[i-1]+1;
            }
        }
        pow10[0] = 1;
        for(int i=1; i<=m; i++){
            pow10[i] = (pow10[i-1]*10)%mod;
        }
        for(int i=0; i<queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            long long sum = (preSum[right+1]-preSum[left]+mod)%mod;
            long long leftPart = conVal[left];
            long long rightPart = conVal[right+1];
            int diffDigits = count[right+1]-count[left];
            long long power = pow10[diffDigits];
            long long range = (rightPart - (leftPart*power)%mod +mod)%mod;
            long long x = (range * sum)%mod;
            ans[i] = (int)x;
        }
        return ans;
    }
};