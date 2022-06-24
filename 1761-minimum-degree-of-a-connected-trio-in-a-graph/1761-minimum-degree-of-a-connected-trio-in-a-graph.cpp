class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int size = edges.size();
        vector<vector<bool>> edgesMatrix(n+1, vector<bool>(n+1, false));
        vector<int> degrees(n+1, 0);
        for(int i=0; i<size; i++){
            edgesMatrix[edges[i][0]][edges[i][1]] = true;
            edgesMatrix[edges[i][1]][edges[i][0]] = true;
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        int ans = INT_MAX;
        for(int i=1; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<=n; k++){
                    if(edgesMatrix[i][j] && edgesMatrix[j][k] && edgesMatrix[k][i]){
                        ans = min(ans, degrees[i]+degrees[j]+degrees[k]-6);
                    }
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};