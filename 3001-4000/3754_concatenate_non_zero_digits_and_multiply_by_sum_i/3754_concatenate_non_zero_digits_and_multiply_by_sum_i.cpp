class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        int pos = 1;
        while(n > 0){
            int lastDigit = n%10;
            n /= 10;
            if(lastDigit > 0){
                x = lastDigit * pos + x;
                pos *= 10;
                sum += lastDigit;
            }
        }
        return x*sum;
    }
};