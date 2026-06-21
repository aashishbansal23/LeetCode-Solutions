class Solution {
    void bfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& target, int& m, int& n){
        queue<pair<int, int>> q;
        q.push({r,c});
        target[r][c] = true;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            r = p.first;
            c = p.second;
            if(r-1>=0 && !target[r-1][c] && heights[r-1][c]>=heights[r][c]){
                target[r-1][c] = true;
                q.push({r-1,c});
            }
            if(r+1<m && !target[r+1][c] && heights[r+1][c]>=heights[r][c]){
                target[r+1][c] = true;
                q.push({r+1,c});
            }
            if(c-1>=0 && !target[r][c-1] && heights[r][c-1]>=heights[r][c]){
                target[r][c-1] = true;
                q.push({r,c-1});
            }
            if(c+1<n && !target[r][c+1] && heights[r][c+1]>=heights[r][c]){
                target[r][c+1] = true;
                q.push({r,c+1});
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            if(!pacific[i][0]){
                bfs(i, 0, heights, pacific, m, n);
            }
            if(!atlantic[i][n-1]){
                bfs(i, n-1, heights, atlantic, m, n);
            }
        }
        for(int i=0; i<n; i++){
            if(!pacific[0][i]){
                bfs(0, i, heights, pacific, m, n);
            }
            if(!atlantic[m-1][i]){
                bfs(m-1, i, heights, atlantic, m, n);
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};