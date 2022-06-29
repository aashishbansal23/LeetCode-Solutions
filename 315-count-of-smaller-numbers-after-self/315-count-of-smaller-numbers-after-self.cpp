class Solution {
    void merge(vector<pair<int, int>>& mp, int s, int mid, int e, vector<int>& ans){
        vector<pair<int, int>> temp(e-s+1);
        int i = s;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j<=e){
            if(mp[i].first <= mp[j].first){
                temp[k++] = mp[j++];
            }else{
                ans[mp[i].second] += e-j+1;
                temp[k++] = mp[i++];
            }
        }
        while(i <= mid){
            temp[k++] = mp[i++];
        }
        while(j <= e){
            temp[k++] = mp[j++];
        }
        for(int i=s; i<=e; i++){
            mp[i] = temp[i-s];
        }
    }
    
    void mergeSort(vector<pair<int, int>>& mp, int s, int e, vector<int>& ans){
        if(s >= e){
            return ;
        }
        int mid = s+(e-s)/2;
        mergeSort(mp, s, mid, ans);
        mergeSort(mp, mid+1, e, ans);
        merge(mp, s, mid, e, ans);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int, int>> mp;
        for(int i=0; i<size; i++){
            mp.push_back({nums[i], i});
        }
        vector<int> ans(size, 0);
        mergeSort(mp, 0, size-1, ans);
        return ans;
    }
};