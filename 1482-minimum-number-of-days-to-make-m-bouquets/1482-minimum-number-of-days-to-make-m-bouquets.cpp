class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if(m*k > size){
            return -1;
        }
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for(int i=0; i<size; i++){
            maxNum = max(maxNum, bloomDay[i]);
            minNum = min(minNum, bloomDay[i]);
        }
        if(m*k == size){
            return maxNum;
        }
        int res = maxNum;
        int low = minNum;
        int high = maxNum;
        while(low <= high){
            int i = low+(high-low)/2;
            int ans = 0;
            int temp = 0;
            for(int j=0; j<size; j++){
                if(bloomDay[j] <= i){
                    temp++;
                }else{
                    ans += (temp/k);
                    temp = 0;
                }
            }
            ans += (temp/k);
            if(ans >= m){
                res = i;
                high = i-1;
            }else{
                low = i+1;
            }
        }
        return res;
    }
};