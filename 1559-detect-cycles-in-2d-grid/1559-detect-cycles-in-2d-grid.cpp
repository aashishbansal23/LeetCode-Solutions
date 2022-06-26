class Solution {
    bool dfs(int r, int c, vector<vector<char>>& grid, int i, int j, int& m, int& n){
        char ch = grid[r][c];
        grid[r][c] = '0';
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for(int k=0; k<4; k++){
            int a = r+x[k];
            int b = c+y[k];
            if(a>=0 && a<m && b>=0 && b<n && (a!=i || b!=j)){
                if(grid[a][b] == '0'){
                    return true;
                }
                if(grid[a][b]==ch && dfs(a, b, grid, r, c, m, n)){
                    return true;
                }
            }
        }
        grid[r][c] = '.';
        return false;
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != '.'){
                    if(dfs(i, j, grid, -1, -1, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};