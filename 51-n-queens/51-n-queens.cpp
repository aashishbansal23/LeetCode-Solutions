class Solution {
    void insertInAns(vector<vector<string>>& ans, vector<vector<string>> board, int n){
        vector<string> temp;
        for(int i=0; i<n; i++){
            string t = "";
            for(int j=0; j<n; j++){
                t += board[i][j];
            }
            temp.push_back(t);
        }
        ans.push_back(temp);
    }
    
    bool isSafe(int row, int col, vector<vector<string>>& board, int n){
        for(int i=0; i<col; i++){
            if(board[row][i] == "Q"){
                return false;
            }
        }
        int x = row;
        int y = col;
        while(x>=0 && y>=0){
            if(board[x][y] == "Q"){
                return false;
            }
            x--;
            y--;
        }
        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x][y] == "Q"){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    
    void solveNQueensHelp(int col, vector<vector<string>>& ans, vector<vector<string>> board, int n){
        if(col == n){
            insertInAns(ans, board, n);
            return ;
        }
        for(int i=0; i<n; i++){
            if(isSafe(i, col, board, n)){
                board[i][col] = "Q";
                solveNQueensHelp(col+1, ans, board, n);
                board[i][col] = ".";
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<string>> board(n, vector<string>(n, "."));
        solveNQueensHelp(0, ans, board, n);
        return ans;
    }
};