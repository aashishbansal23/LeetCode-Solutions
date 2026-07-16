class Solution {
    int gcd(int num1, int num2){
        if(num1==0 || num2==0){
            return max(num1, num2);
        }
        while(num2 != 0){
            int temp = num2;
            num2 = num1%num2;
            num1 = temp;
        }
        return num1;
    }

public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int preMx = nums[0];
        vector<int> prefixGcd(n, nums[0]);
        for(int i=1; i<n; i++){
            preMx = max(preMx, nums[i]);
            prefixGcd[i] = gcd(preMx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i=0, j=n-1;
        long long ans = 0;
        while(i < j){
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};