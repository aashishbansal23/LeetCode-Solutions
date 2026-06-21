class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int columns = colSum.size();
        vector<vector<int>> ans(rows, vector<int>(columns, -1));
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                ans[i][j] = min(rowSum[i], colSum[j]);
                if(ans[i][j] == rowSum[i]){
                    rowSum[i] = 0;
                    colSum[j] -= ans[i][j];
                }else{
                    colSum[j] = 0;
                    rowSum[i] -= ans[i][j];
                }
            }
        }
        return ans;
    }
};