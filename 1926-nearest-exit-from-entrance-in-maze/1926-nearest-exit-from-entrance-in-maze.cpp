class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int ans = 0;
        queue<pair<int,int>>qu;
        qu.push({entrance[0], entrance[1]});
        
        while(!qu.empty()){
            int size = qu.size();
            
            while(size--){
                int i = qu.front().first;
                int j = qu.front().second;
                qu.pop();
                
                if((i == 0 or j == 0 or i==grid.size()-1 or j == grid[0].size()-1) and (i!=entrance[0] or j!=entrance[1])){
                    return ans;
                }
                
                for(int d = 0; d<4; d++){
                    int currx = i+dx[d];
                    int curry = j+dy[d];

                    if(currx>=0 and currx<grid.size() and curry>=0 and curry<grid[0].size() and grid[currx][curry]=='.'){
                        grid[currx][curry] = '+';       
                        qu.push({currx, curry});
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};




// class Solution {
// public:
//     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//         int m = maze.size();
//         int n = maze[0].size();
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         int r = entrance[0];
//         int c = entrance[1];
//         visited[r][c] = true;
//         queue<pair<int, int>> q;
//         int ans = 1;
//         bool flag = true;
//         if(r-1>=0 && maze[r-1][c]=='.' && !visited[r-1][c]){
//             q.push({r-1, c});
//             visited[r-1][c] = true;
//             flag = false;
//         }
//         if(r+1<m && maze[r+1][c]=='.' && !visited[r+1][c]){
//             q.push({r+1, c});
//             visited[r+1][c] = true;
//             flag = false;
//         }
//         if(c-1>=0 && maze[r][c-1]=='.' && !visited[r][c-1]){
//             q.push({r, c-1});
//             visited[r][c-1] = true;
//             flag = false;
//         }
//         if(c+1<n && maze[r][c+1]=='.' && !visited[r][c+1]){
//             q.push({r, c+1});
//             visited[r][c+1] = true;
//             flag = false;
//         }
//         if(flag){
//             return -1;
//         }
//         while(!q.empty()){
//             int size = q.size();
//             while(size > 0){
//                 pair<int, int> p = q.front();
//                 q.pop();
//                 int r = p.first;
//                 int c = p.second;
//                 if(r-1>=0 && maze[r-1][c]=='.' && !visited[r-1][c]){
//                     q.push({r-1, c});
//                     visited[r-1][c] = true;
//                 }else if(r-1 < 0){
//                     return ans;
//                 }
//                 if(r+1<m && maze[r+1][c]=='.' && !visited[r+1][c]){
//                     q.push({r+1, c});
//                     visited[r+1][c] = true;
//                 }else if(r+1 >= m){
//                     return ans;
//                 }
//                 if(c-1>=0 && maze[r][c-1]=='.' && !visited[r][c-1]){
//                     q.push({r, c-1});
//                     visited[r][c-1] = true;
//                 }else if(c-1 < 0){
//                     return ans;
//                 }
//                 if(c+1<n && maze[r][c+1]=='.' && !visited[r][c+1]){
//                     q.push({r, c+1});
//                     visited[r][c+1] = true;
//                 }else if(c+1 >= n){
//                     return ans;
//                 }
//                 size--;
//             }
//             ans++;
//         }
//         return ans;
//     }
// };