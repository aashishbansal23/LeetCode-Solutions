class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> total(size+1, 0);
        for(int i=0; i<size; i++){
            total[edges[i][0]-1]++;
            total[edges[i][1]-1]++;
        }
        for(int i=0; i<size+1; i++){
            if(total[i] == size){
                return i+1;
            }
        }
        return -1;
    }
};