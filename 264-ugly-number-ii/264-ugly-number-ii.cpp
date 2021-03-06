class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int two = 0;
        int three = 0;
        int five = 0;
        for(int i=1; i<n; i++){
            dp[i] = min(2*dp[two], min(3*dp[three], 5*dp[five]));
            if(dp[i] == 2*dp[two]){
                two++;
            }
            if(dp[i] == 3*dp[three]){
                three++;
            }
            if(dp[i] == 5*dp[five]){
                five++;
            }
        }
        return dp[n-1];
        
        
        
        
        
        
        
        
        
        // First Try
        // priority_queue<int, vector<int>, greater<int>> pq;
        // pq.push(1);
        // long long ans = 1;
        // set<int> st;
        // st.insert(1);
        // while(n > 0){
        //     ans = pq.top();
        //     pq.pop();
        //     if(2*ans<=INT_MAX && st.find(2*ans)==st.end()){
        //         pq.push(2*ans);
        //         st.insert(2*ans);
        //     }
        //     if(3*ans<=INT_MAX && st.find(3*ans)==st.end()){
        //         pq.push(3*ans);
        //         st.insert(3*ans);
        //     }
        //     if(5*ans<=INT_MAX && st.find(5*ans)==st.end()){
        //         pq.push(5*ans);
        //         st.insert(5*ans);
        //     }
        //     n--;
        // }
        // return ans;
    }
};