class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // (n)+(n+1)+(n+2) = num  => n = (num-3)/3
        if((num-3)%3 != 0){
            return {};
        }
        vector<long long> ans;
        long long n = (num-3)/3;
        for(int i=0; i<3; i++){
            ans.push_back(n+i);
        }
        return ans;
    }
};