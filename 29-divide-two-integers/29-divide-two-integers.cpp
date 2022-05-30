class Solution {
public:
    int divide(int dividend, int divisor) {
        // long long sum = 0;
        // long long ans = 0;
        // long long ds = abs(divisor);
        // long long dd = abs(dividend);
        // while(sum <= dd){
        //     sum += ds;
        //     ans++;
        // }
        // ans--;
        // if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)){
        //     if(ans > INT_MAX){
        //         return INT_MAX;
        //     }else{
        //         return ans;
        //     }
        // }else{
        //     ans = ans*(-1);
        //     if(ans < INT_MIN){
        //         return INT_MIN;
        //     }else{
        //         return ans;
        //     }
        // }
        
        
        
        ///*
        if(dividend == 0){
            return 0;
        }
        
        long long ds = abs(divisor);
        long long dd = abs(dividend);
        long long s = 0;
        long long e = dd;
        long long ans = dd;
        while(s <= e){
            long long mid = s+(e-s)/2;
            if(mid*(abs(ds)) == abs(dd)){
                ans = mid;
                break;
            }else if(mid*(abs(ds)) > abs(dividend)){
                e = mid-1;
            }else{
                ans = mid;
                s = mid+1;
            }
        }
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)){
            if(ans > INT_MAX){
                return INT_MAX;
            }else if(ans < INT_MIN){
                return INT_MIN;
            }
            return ans;
        }else{
            ans =  -1*ans;
            if(ans > INT_MAX){
                return INT_MAX;
            }else if(ans < INT_MIN){
                return INT_MIN;
            }
            return ans;
        }
        //*/
    }
};