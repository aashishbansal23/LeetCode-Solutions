class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto edge:edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==k || j==k || i==j || dist[i][k]==INT_MAX || dist[k][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        int ans = 0;
        int minn = INT_MAX;
        for(int i=0; i<n; i++){
            int temp = 0;
            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    temp++;
                }
            }
            if(minn >= temp){
                minn = temp;
                ans = i;
            }
        }
        return ans;
    }
};