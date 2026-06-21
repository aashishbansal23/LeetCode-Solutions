class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        if(r <= 1){
            return mat;
        }
        int c = mat[0].size();
        if(c <= 1){
            return mat;
        }
        
        for(int count=0; count<c; count++){
            int i = 0;
            int j = count;
            vector<int> temp;
            while(i<r && j<c){
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());
            i = 0;
            j = count;
            int k = 0;
            while(i<r && j<c){
                mat[i][j] = temp[k];
                i++;
                j++;
                k++;
            }
        }
        
        for(int count=1; count<r; count++){
            int i = count;
            int j = 0;
            vector<int> temp;
            while(i<r && j<c){
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());
            i = count;
            j = 0;
            int k = 0;
            while(i<r && j<c){
                mat[i][j] = temp[k];
                i++;
                j++;
                k++;
            }
        }
        return mat;
    }
};