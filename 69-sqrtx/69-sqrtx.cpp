class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        int ans = 0;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(mid <= (int)x/mid){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
        
        
        // int i=1;
        // while(i <= (int)x/i){
        //     i++;
        // }
        // return i-1;
    }
};