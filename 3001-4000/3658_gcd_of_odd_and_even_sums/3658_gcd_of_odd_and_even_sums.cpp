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
    int gcdOfOddEvenSums(int n) {
        // int sumEven = n*(n+1);
        // int sumFirst2n = n*(2*n+1);
        // int sumOdd = sumFirst2n-sumEven; // int sumOdd = n*n;
        // return gcd(sumEven, sumOdd);
        return n;
    }
};