class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int maxx = arr[size-1];
        if(maxx-size < k){
            k = k-(maxx-size);
            return maxx+k;
        }
        int j = 0;
        for(int i=1; i<=maxx; i++){
            if(arr[j] == i){
                j++;
            }else{
                k--;
                if(k == 0){
                    return i;
                }
            }
        }
        return maxx;
    }
};