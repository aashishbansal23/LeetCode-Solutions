class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1000000007;
        int n = board.size();
        vector<int> v;
        if(n == 0){
            return v;
        }
        int m = board[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2)));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1){
                    dp[i][j] = {0, 1};
                }else if(board[i][j] == 'X'){
                    dp[i][j] = {INT_MIN, 0};
                }else{
                    long val = INT_MIN;
                    long count = 0;
                    if(j+1<m && dp[i][j+1][0]!=INT_MIN){
                        val = dp[i][j+1][0];
                        count = dp[i][j+1][1];
                    }
                    if(i+1<n && dp[i+1][j][0]!=INT_MIN && val<=dp[i+1][j][0]){
                        if(val < dp[i+1][j][0]){
                            val = dp[i+1][j][0];
                            count = dp[i+1][j][1];
                        }else{
                            count = (count+dp[i+1][j][1])%mod;
                        }
                    }
                    if(i+1<n && j+1<m && dp[i+1][j+1][0]!=INT_MIN && val<=dp[i+1][j+1][0]){
                        if(val < dp[i+1][j+1][0]){
                            val = dp[i+1][j+1][0];
                            count = dp[i+1][j+1][1];
                        }else{
                            count = (count+dp[i+1][j+1][1])%mod;
                        }
                    }
                    if(val == INT_MIN){
                        dp[i][j] = {INT_MIN, 0};
                    }else if(i==0 && j==0){
                        dp[i][j] = {(int)val, (int)(count%mod)};
                    }
                    else{
                        dp[i][j] = {(int)val+(board[i][j]-'0'), (int)(count%mod)};
                    }
                }
            }
        }
        if(dp[0][0][0] == INT_MIN){
            v.push_back(0);
            v.push_back(0);
            return v;
        }
        return dp[0][0];
    }
};