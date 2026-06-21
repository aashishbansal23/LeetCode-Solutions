class Solution {
    bool searchRow(vector<vector<int>>& matrix, int i, int e, int target){
        int s = 0;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(matrix[i][mid] == target){
                return true;
            }else if(matrix[i][mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0){
            return false;
        }
        int n = matrix[0].size();
        if((target < matrix[0][0]) || (target > matrix[m-1][n-1])){
            return false;
        }
        
        for(int i=0; i<m; i++){
            if((target >= matrix[i][0]) && (target <= matrix[i][n-1])){
                return searchRow(matrix, i, n-1, target);
            }
        }
        return false;
        
        
        
        // for(int i=0; i<matrix.size(); i++){
        //     if(target>=matrix[i][0] && target<=matrix[i][matrix[i].size()-1]){
        //         for(int j=0; j<matrix[i].size(); j++){
        //             if(matrix[i][j]==target){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
    }
};