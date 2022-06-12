class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int columns = colsum.size();
        vector<vector<int>> ans(2, vector<int>(columns, 0));
        vector<vector<int>> temp;
        for(int j=0; j<columns; j++){
            if(colsum[j] > 2){
                return temp;
            }else if(colsum[j] == 2){
                ans[0][j] = 1;
                ans[1][j] = 1;
                colsum[j] = 0;
                upper--;
                lower--;
            }
            if(upper<0 || lower<0){
                return temp;
            }
        }
        for(int j=0; j<columns; j++){
            if(colsum[j] == 1){
                if(upper > 0){
                    ans[0][j] = 1;
                    colsum[j]--;
                    upper--;
                }else if(lower > 0){
                    ans[1][j] = 1;
                    colsum[j]--;
                    lower--;
                }else{
                    return temp;
                }
            }
        }
        if(upper!=0 || lower!=0){
            return temp;
        }else{
            return ans;
        }
    }
};