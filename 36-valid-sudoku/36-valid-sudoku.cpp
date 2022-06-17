class Solution {
    bool isSafe(int row, int col, char val, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(i!=col && board[row][i]==val){
                return false;
            }
            if(i!=row && board[i][col]==val){
                return false;
            }
            int x = 3*(row/3)+i/3;
            int y = 3*(col/3)+i%3;
            if(x!=row || y!=col){
                if(board[x][y] == val){
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(!isSafe(i, j, board[i][j], board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};