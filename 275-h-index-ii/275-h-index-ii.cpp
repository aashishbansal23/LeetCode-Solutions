class Solution {
    int helper(vector<int>& citations, int i, int j, int len){
        int ans = 0;
        if(i <= j){
            int mid = i+(j-i)/2;
            int temp = min(len-mid, citations[mid]);
            ans = max(ans, temp);
            temp = helper(citations, mid+1, j, len);
            ans = max(ans, temp);
            temp = helper(citations, i, mid-1, len);
            ans = max(ans, temp);
        }
        return ans;
    }
    
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int len = citations.size();
        int i=0, j=len-1;
        ans = helper(citations, i, j, len);
        return ans;
    }
};