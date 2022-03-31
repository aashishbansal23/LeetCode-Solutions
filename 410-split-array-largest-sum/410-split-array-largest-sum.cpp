class Solution {
    bool check(vector<int>& nums, int m, int curr){
        int i = -1;
        int n = nums.size();
        int count = 1;
        int sum = 0;
        while(++i<n && count<=m){
            if(sum+nums[i] <= curr){
                sum += nums[i];
            }else{
                sum = nums[i];
                count++;
            }
        }
        return count<=m;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int e = 0;
        int s = 0;
        int mid, ans;
        for(auto x:nums){
            e += x;
            s = max(s, x);
        }
        ans = e;
        while(s <= e){
            mid = s+(e-s)/2;
            if(check(nums, m, mid)){
                ans = min(ans, mid);
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};