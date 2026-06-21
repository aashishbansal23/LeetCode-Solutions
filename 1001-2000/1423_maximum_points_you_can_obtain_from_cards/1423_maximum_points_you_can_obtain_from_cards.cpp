class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        if(size < k){
            return -1;
        }
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
        }
        int ans = sum;
        for(int i=k-1; i>=0; i--){
            sum -= cardPoints[i];
            sum += cardPoints[--size];
            ans = max(ans, sum);
        }
        return ans;
    }
};