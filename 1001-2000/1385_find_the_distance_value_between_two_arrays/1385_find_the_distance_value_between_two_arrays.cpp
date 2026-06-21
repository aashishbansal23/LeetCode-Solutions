class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int size1 = arr1.size();
        int size2 = arr2.size();
        int ans = 0;
        for(int i=0; i<size1; i++){
            int low = 0;
            int high = size2-1;
            bool flag = true;
            while(low <= high){
                int mid = low+(high-low)/2;
                if(abs(arr1[i]-arr2[mid]) <= d){
                    flag = false;
                    break;
                }else if(arr2[mid] > arr1[i]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};