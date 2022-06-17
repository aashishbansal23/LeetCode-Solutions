class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i=0, j=0;
        int ansSum = 0;
        while(i<n && j<n){
            ansSum += mat[i][j];
            i++;
            j++;
        }
        i = 0;
        j = n-1;
        while(i<n && j>=0){
            ansSum += mat[i][j];
            i++;
            j--;
        }
        if((n&1) == 1){
            ansSum -= mat[n/2][n/2];
        }
        return ansSum;
    }
};