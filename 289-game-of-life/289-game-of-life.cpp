class Solution {
    bool check(vector<vector<int>>& temp, int i, int j, int m, int n){
        int zero = 0;
        int one = 0;
        if(i>0 && j>0){
            if(temp[i-1][j-1] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(i > 0){
            if(temp[i-1][j] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(i>0 && j<n){
            if(temp[i-1][j+1] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(j > 0){
            if(temp[i][j-1] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(j < n){
            if(temp[i][j+1] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(i<m && j>0){
            if(temp[i+1][j-1] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(i < m){
            if(temp[i+1][j] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(i<m && j<n){
            if(temp[i+1][j+1] == 0){
                zero++;
            }else{
                one++;
            }
        }
        
        if(temp[i][j] == 0){
            if(one == 3){
                return true;
            }else{
                return false;
            }
        }else{
            if(one<2 || one>3){
                return true;
            }else{
                return false;
            }
        }
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int m = board.size();
        if(m <= 0){
            return ;
        }
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check(temp, i, j, m-1, n-1)){
                    if(board[i][j] == 1){
                        board[i][j] = 0;
                    }else{
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};