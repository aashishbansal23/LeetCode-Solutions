class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[row][col] == color){
            return grid;
        }
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited.insert({row, col});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            row = p.first;
            col = p.second;
            bool flag = false;
            if(row-1>=0){
                if(grid[row-1][col] == grid[row][col]){
                    if(visited.count({row-1, col}) == 0){
                        q.push({row-1, col});
                        visited.insert({row-1, col});
                    }
                }else if(visited.count({row-1, col}) == 0){
                    flag = true;
                    // grid[row][col] = color;
                }
            }else{
                flag = true;
            }
            if(row+1 < m){
                if(grid[row+1][col] == grid[row][col]){
                    if(visited.count({row+1, col}) == 0){
                        q.push({row+1, col});
                        visited.insert({row+1, col});
                    }
                }else if(visited.count({row+1, col}) == 0){
                    flag = true;
                    // grid[row][col] = color;
                }
            }else{
                flag = true;
            }
            if(col-1 >= 0){
                if(grid[row][col-1] == grid[row][col]){
                    if(visited.count({row, col-1}) == 0){
                        q.push({row, col-1});
                        visited.insert({row, col-1});
                    }
                }else if(visited.count({row, col-1}) == 0){
                    flag = true;
                    // grid[row][col] = color;
                }
            }else{
                flag = true;
            }
            if(col+1 < n){
                if(grid[row][col+1] == grid[row][col]){
                    if(visited.count({row, col+1}) == 0){
                        q.push({row, col+1});
                        visited.insert({row, col+1});
                    }
                }else if(visited.count({row, col+1}) == 0){
                    flag = true;
                    // grid[row][col] = color;
                }
            }else{
                flag = true;
            }
            if(flag){
                grid[row][col] = color;
            }
        }
        return grid;
    }
};