class Solution {
    int getCount(vector<int>& v){
        int size = v.size();
        int s = 0;
        int e = size-1;
        int ans = 0;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(v[mid] < 0){
                ans = size-mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
    
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            ans += getCount(grid[i]);
        }
        return ans;
        
//         int ans = 0;
//         int m = grid.size();
//         if(m == 0){
//             return ans;
//         }
//         int n = grid[0].size();
        
//         int i=0, j=0;
//         for(i=0; i<m; i++){
//             for(j=0; j<n; j++){
//                 if(grid[i][j] < 0){
//                     ans += (n-j);
//                     break;
//                 }
//             }
//         }
//         return ans;
    }
};