class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
        
        
        
        
        // First Try BFS
        // set<int> s;
        // queue<int> q;
        // q.push(n);
        // s.insert(n);
        // int count = 1;
        // while(!q.empty()){
        //     int size = q.size();
        //     while(size-- > 0){
        //         n = q.front();
        //         q.pop();
        //         int num = sqrt(n);
        //         if(num*num == n){
        //             return count;
        //         }
        //         for(int i=1; i<n; i++){
        //             if(n-i*i>=0 && s.count(n-i*i)==0){
        //                 q.push(n-i*i);
        //                 s.insert(n-i*i);
        //             }else if(n-i*i < 0){
        //                 break;
        //             }
        //         }
        //     }
        //     count++;
        // }
        // return count;
    }
};