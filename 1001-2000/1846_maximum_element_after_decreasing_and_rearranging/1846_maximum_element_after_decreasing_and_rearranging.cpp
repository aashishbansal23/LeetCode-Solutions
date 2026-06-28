class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int arrSize = arr.size();
        if(arrSize == 0){
            return 0;
        }
        vector<int> frequency(arrSize+1, 0);
        for(int a:arr){
            frequency[min(a, arrSize)]++;
        }
        int val = 0;
        for(int i=1; i<=arrSize; i++){
            val = min(i, val+frequency[i]);
        }
        return val;
    }
};