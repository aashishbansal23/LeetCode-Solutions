class Solution {
    bool isSafe(int row, int col, int val, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[row][i]==val+'0' || board[i][col]==val+'0'){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val+'0'){
                return false;
            }
        }
        return true;
    }
    
    bool solveSudokuHelp(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int k=1; k<=9; k++){
                        if(isSafe(i, j, k, board)){
                            board[i][j] = k+'0';
                            bool ans = solveSudokuHelp(board);
                            if(ans){
                                return ans;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelp(board);
    }
};