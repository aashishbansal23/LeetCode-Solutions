class Solution {
    bool isSafe(int row, int col, vector<vector<bool>>& board, int n){
        int x = row;
        int y = 0;
        while(y < col){
            if(board[x][y]){
                return false;
            }
            y++;
        }
        y = col;
        while(x>=0 && y>=0){
            if(board[x][y]){
                return false;
            }
            x--;
            y--;
        }
        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x][y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    
    void totalNQueensHelp(int col, vector<vector<bool>>& board, int n, int& ans){
        if(col == n){
            ans++;
            return ;
        }
        for(int i=0; i<n; i++){
            if(isSafe(i, col, board, n)){
                board[i][col] = true;
                totalNQueensHelp(col+1, board, n, ans);
                board[i][col] = false;
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int ans = 0;
        totalNQueensHelp(0, board, n, ans);
        return ans;
    }
};