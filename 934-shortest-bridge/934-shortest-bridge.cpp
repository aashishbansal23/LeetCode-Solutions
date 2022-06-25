class Solution {
    void getIsland(int row, int col, vector<vector<int>>& grid, queue<pair<int, int>>& nodes, vector<vector<bool>>& visited){
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({row, col});
        nodes.push({row, col});
        visited[row][col] = true;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r-1>=0 && grid[r-1][c]==1 && !visited[r-1][c]){
                q.push({r-1, c});
                nodes.push({r-1, c});
                visited[r-1][c] = true;
            }
            if(r+1<n && grid[r+1][c]==1 && !visited[r+1][c]){
                q.push({r+1, c});
                nodes.push({r+1, c});
                visited[r+1][c] = true;
            }
            if(c-1>=0 && grid[r][c-1]==1 && !visited[r][c-1]){
                q.push({r, c-1});
                nodes.push({r, c-1});
                visited[r][c-1] = true;
            }
            if(c+1<n && grid[r][c+1]==1 && !visited[r][c+1]){
                q.push({r, c+1});
                nodes.push({r, c+1});
                visited[r][c+1] = true;
            }
        }
    }
    
    int getNumberOfZeroes(vector<vector<int>>& grid, queue<pair<int, int>>& q, vector<vector<bool>>& visited){
        int n = grid.size();
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if(r-1>=0 && !visited[r-1][c]){
                    if(grid[r-1][c] == 1){
                        return ans;
                    }
                    q.push({r-1, c});
                    visited[r-1][c] = true;
                }
                if(r+1<n && !visited[r+1][c]){
                    if(grid[r+1][c] == 1){
                        return ans;
                    }
                    q.push({r+1, c});
                    visited[r+1][c] = true;
                }
                if(c-1>=0 && !visited[r][c-1]){
                    if(grid[r][c-1] == 1){
                        return ans;
                    }
                    q.push({r, c-1});
                    visited[r][c-1] = true;
                }
                if(c+1<n && !visited[r][c+1]){
                    if(grid[r][c+1] == 1){
                        return ans;
                    }
                    q.push({r, c+1});
                    visited[r][c+1] = true;
                }
                size--;
            }
            ans++;
        }
        return ans;
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> nodes;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    getIsland(i, j, grid, nodes, visited);
                    ans = getNumberOfZeroes(grid, nodes, visited);
                    break;
                }
            }
            if(ans != 0){
                break;
            }
        }
        return ans;
    }
};