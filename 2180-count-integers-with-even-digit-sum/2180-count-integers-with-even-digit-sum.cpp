class Solution {
public:
    int countEven(int num) {
        int temp = num;
        int sum = 0;
        while(temp > 0){
            sum += (temp%10);
            temp /= 10;
        }
        if((sum&1) == 0){
            return num/2;
        }else{
            return (num-1)/2;
        }
    }
};