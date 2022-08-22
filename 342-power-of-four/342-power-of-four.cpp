class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }
        float ans = log(n)/log(4);
        if(ans == (int)ans){
            return true;
        }else{
            return false;
        }
    }
};