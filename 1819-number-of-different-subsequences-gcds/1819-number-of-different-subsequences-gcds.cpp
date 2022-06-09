class Solution {
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }
    
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int ans = 0;
        int maxx = *max_element(nums.begin(), nums.end());
        vector<int> v(maxx+1, 0);
        for(auto i:nums){
            v[i] = 1;
        }
        for(int i=1; i<=maxx; i++){
            int currGCD = 0;
            for(int j=i; j<=maxx; j+=i){
                if(v[j] == 1){
                    currGCD = gcd(currGCD, j);
                    if(currGCD == i){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};