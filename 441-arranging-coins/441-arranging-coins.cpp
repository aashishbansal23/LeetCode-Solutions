class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 1;
        int low = 1;
        int high = n;
        while(low <= high){
            long long mid = low+(high-low)/2;
            long long temp = (mid*(mid+1)/2);
            if(temp <= n){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};