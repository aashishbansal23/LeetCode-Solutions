class Solution {
    bool check(vector<vector<char>>& board, int i, int j, int& m, int& n, vector<vector<bool>>& visited){
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = true;
        bool flag = true;
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int x = i+dx[k];
                int y = j+dy[k];
                if(x>=0 && x<m && y>=0 && y<n){
                    if(board[x][y]=='O' && !visited[x][y]){
                        q.push({x,y});
                        visited[x][y] = true;
                    }
                }else{
                    flag = false;
                }
            }
        }
        return flag;
    }
    
    void replace(vector<vector<char>>& board, int i, int j, int& m, int& n){
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        queue<pair<int,int>> q;
        q.push({i,j});
        board[i][j] = 'X';
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int x = i+dx[k];
                int y = j+dy[k];
                if(x>=0 && x<m && y>=0 && y<n && board[x][y] == 'O'){
                    q.push({x,y});
                    board[x][y] = 'X';
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    if(check(board, i, j, m, n, visited)){
                        replace(board, i, j, m, n);
                    }
                }
            }
        }
    }
};