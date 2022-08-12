class TreeAncestor {
    vector<vector<int>> ancestor;
    int m;
    int n;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        m = 18;
        this->n = n;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[0][i] = parent[i];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                // cout << i << " " << j << endl;
                if(dp[i-1][j] == -1){
                    dp[i][j] = -1;
                }else{
                    dp[i][j] = dp[i-1][dp[i-1][j]];
                }
            }
        }
        ancestor = dp;
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0; i<m; i++){
            if(node == -1){
                break;
            }
            int mask = (1<<i);
            if((k&mask) > 0){
                node = ancestor[i][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */