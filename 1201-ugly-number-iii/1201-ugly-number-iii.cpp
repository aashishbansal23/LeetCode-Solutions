class Solution {
    long long gcd(long long a, long long b){
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }
    
    long long lcm(long long a, long long b){
        return a*b/gcd(max(a,b), min(a,b));
    }
    
    int count(long long mid, long long a, long long b, long long c){
        return (int)(mid/a + mid/b + mid/c - mid/lcm(a,b) - mid/lcm(b,c) - mid/lcm(a,c) + mid/lcm(a,lcm(b,c)));
    }
    
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int low = 1;
        int high = INT_MAX;
        int ans = 1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(count(mid, a, b, c) >= n){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        
        
        
        
        // First Try Gives TLE
        // int ans = 1;
        // int counter = 1;
        // while(n > 0){
        //     if(counter%a==0 || counter%b==0 || counter%c==0){
        //         ans = counter;
        //         n--;
        //     }
        //     counter++;
        // }
        // return ans;
    }
};