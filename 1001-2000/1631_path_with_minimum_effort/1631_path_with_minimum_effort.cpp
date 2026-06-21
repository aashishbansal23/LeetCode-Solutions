class Solution {
    bool isPossible(vector<vector<int>>& heights, int mid, int rows, int cols){
        int diff = INT_MAX;
        queue<pair<int, int>> q;
        q.push({0, 0});
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i==rows-1 && j==cols-1){
                return true;
            }
            if(i-1>=0 && visited.count({i-1,j})==0 && abs(heights[i][j]-heights[i-1][j])<=mid){
                q.push({i-1, j});
                visited.insert({i-1, j});
            }
            if(i+1<rows && visited.count({i+1,j})==0 && abs(heights[i][j]-heights[i+1][j])<=mid){
                q.push({i+1, j});
                visited.insert({i+1, j});
            }
            if(j-1>=0 && visited.count({i,j-1})==0 && abs(heights[i][j]-heights[i][j-1])<=mid){
                q.push({i, j-1});
                visited.insert({i, j-1});
            }
            if(j+1<cols && visited.count({i,j+1})==0 && abs(heights[i][j]-heights[i][j+1])<=mid){
                q.push({i, j+1});
                visited.insert({i, j+1});
            }
        }
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = INT_MAX;
        int rows = heights.size();
        int cols = heights[0].size();
        int low = 0;
        int high = 1000000;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(isPossible(heights, mid, rows, cols)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};