class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        visited[sr][sc] = true;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r-1>=0 && image[r-1][c]==image[r][c] && !visited[r-1][c]){
                q.push(make_pair(r-1, c));
                visited[r-1][c] = true;
            }
            if(r+1<m && image[r+1][c]==image[r][c] && !visited[r+1][c]){
                q.push(make_pair(r+1, c));
                visited[r+1][c] = true;
            }
            if(c-1>=0 && image[r][c-1]==image[r][c] && !visited[r][c-1]){
                q.push(make_pair(r, c-1));
                visited[r][c-1] = true;
            }
            if(c+1<n && image[r][c+1]==image[r][c] && !visited[r][c+1]){
                q.push(make_pair(r, c+1));
                visited[r][c+1] = true;
            }
            image[r][c] = color;
        }
        return image;
    }
};