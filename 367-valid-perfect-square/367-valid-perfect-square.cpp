class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(mid==num/mid && num%mid==0){
                return true;
            }else if(num/mid > mid){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};