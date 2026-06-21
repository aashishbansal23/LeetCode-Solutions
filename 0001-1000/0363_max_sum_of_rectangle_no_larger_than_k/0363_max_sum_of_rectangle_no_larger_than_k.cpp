class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int> sum(m, 0);
            for(int j=i; j<n; j++){
                for(int l=0; l<m; l++){
                    sum[l] += matrix[l][j];
                }
                set<int> st = {0};
                int total = 0;
                for(auto s:sum){
                    total += s;
                    auto itr = st.lower_bound(total-k);
                    if(itr != end(st)){
                        ans = max(ans, total-*itr);
                    }
                    st.insert(total);
                }
            }
        }
        return ans;
    }
};