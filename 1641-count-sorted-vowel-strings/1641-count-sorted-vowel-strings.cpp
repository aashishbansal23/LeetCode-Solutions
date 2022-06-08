class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> values(5, 1);
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=1; j<5; j++){
                values[j] += values[j-1];
            }
        }
        for(int i=0; i<5; i++){
            ans += values[i];
        }
        return ans;
        
        
        
        // First Try
        // return ((n+1)*(n+2)*(n+3)*(n+4))/24;
    }
};