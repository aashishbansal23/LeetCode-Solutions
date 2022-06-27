class Solution {
public:
    int minPartitions(string n) {
        int maxx = INT_MIN;
        for(auto ch:n){
            maxx = max(maxx, (int)(ch-'0'));
        }
        return maxx;
    }
};