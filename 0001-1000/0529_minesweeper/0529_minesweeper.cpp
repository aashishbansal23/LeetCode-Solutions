class Solution {
    int checkNeighbours(vector<vector<char>>& board, int r, int c){
        int m = board.size();
        int n = board[0].size();
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        int ans = 0;
        bool flag = false;
        for(int i=0; i<8; i++){
            int x = r+dx[i];
            int y = c+dy[i];
            if(x>=0 && y>=0 && x<m && y<n){
                if(board[x][y]=='M' || board[x][y]=='X'){
                    ans++;
                }
            }
        }
        return ans;
    }
    
    void updateBoardHelp(vector<vector<char>>& board, vector<int>& click){
        int m = board.size();
        int n = board[0].size();
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return ;
        }
        int count = checkNeighbours(board, x, y);
        if(count == 0){
            board[x][y] = 'B';
            int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
            int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
            for(int i=0; i<8; i++){
                int r = x+dx[i];
                int c = y+dy[i];
                if(r>=0 && r<m && c>=0 && c<n && board[r][c]=='E'){
                    click[0] = r;
                    click[1] = c;
                    updateBoardHelp(board, click);
                }
            }
        }else{
            board[x][y] = ('0'+count);
            return ;
        }
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        updateBoardHelp(board, click);
        return board;
    }
};