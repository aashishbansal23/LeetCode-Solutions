class Solution {
    int binarySearch(vector<int>& vec, int maxVal, vector<vector<int>>& envelopes, int i){
        int l = 0;
        int r = maxVal;
        int temp = maxVal;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(vec[mid] < envelopes[i][1]){
                l = mid+1;
            }else{
                temp = mid;
                r = mid-1;
            }
        }
        return temp;
    }
    
    static bool comp(vector<int>& v1, vector<int>& v2){
        if(v1[0] == v2[0]){
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if(size == 0){
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> vec(size, 0);
        int maxVal = 0;
        for(int i=0; i<size; i++){
            int pos = binarySearch(vec, maxVal, envelopes, i);
            vec[pos] = envelopes[i][1];
            if(pos == maxVal){
                maxVal++;
            }
        }
        return maxVal;
    }
};