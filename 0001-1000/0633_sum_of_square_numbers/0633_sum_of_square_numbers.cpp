class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c <= 1){
            return true;
        }
        long long low = 0;
        long long high = sqrt(c);
        while(low <= high){
            if(low*low+high*high == c){
                return true;
            }else if(low*low+high*high > c){
                high--;
            }else{
                low++;
            }
        }
        return false;
    }
};