class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> tempMat(m, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                if(i == 0){
                    tempMat[i][j] = mat[i][j];
                }else{
                    tempMat[i][j] = tempMat[i-1][j]+mat[i][j];
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = 0;
                int startRow = (i-k<0)?0:i-k;
                int endRow = (i+k>=m)?m-1:i+k;
                int startColumn = (j-k<0)?0:j-k;
                int endColumn = (j+k>=n)?n-1:j+k;
                for(int t=startColumn; t<=endColumn; t++){
                    mat[i][j] += tempMat[endRow][t];
                }
                if(startRow > 0){
                    for(int t=startColumn; t<=endColumn; t++){
                        mat[i][j] -= tempMat[startRow-1][t];
                    }
                }
            }
        }
        return mat;
    }
};