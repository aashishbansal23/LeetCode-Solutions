class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> cols;
        for(int i=0; i<m; i++){
            bool flag = false;
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    flag = true;
                    cols.push_back(j);
                }
            }
            if(flag){
                for(int k=0; k<n; k++){
                    matrix[i][k] = 0;
                }
            }
        }
        for(auto j:cols){
            for(int i=0; i<m; i++){
                matrix[i][j] = 0;
            }
        }
    }
};