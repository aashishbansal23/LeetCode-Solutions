class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int arrSize = arr.size();
        if(arrSize == 0){
            return 0;
        }
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i=1; i<arrSize; i++){
            if(arr[i] > arr[i-1]){
                arr[i] = arr[i-1]+1;
            }
        }
        return arr[arrSize-1];
    }
};