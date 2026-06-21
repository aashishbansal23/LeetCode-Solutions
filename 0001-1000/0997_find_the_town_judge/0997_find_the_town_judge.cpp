class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> total(n, 0);
        for(int i=0; i<trust.size(); i++){
            total[trust[i][0]-1]--;
            total[trust[i][1]-1]++;
        }
        for(int i=0; i<n; i++){
            if(total[i] == n-1){
                return i+1;
            }
        }
        return -1;
    }
};