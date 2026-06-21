class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<pair<int,int>> pq; // Sum, index
        pq.push({nums[0], 0});
        int maxx = nums[0];
        for(int i=1; i<size; i++){
            while(i-pq.top().second > k){
                pq.pop();
            }
            maxx = nums[i]+pq.top().first;
            pq.push({maxx,i});
        }
        return maxx;
        
        
        
        
        
        
        // First Try Brute Force
        // int size = nums.size();
        // vector<int> jump(size, INT_MIN);
        // jump[0] = nums[0];
        // for(int i=0; i<size; i++){
        //     for(int j=i+1; j<=min(i+k, size-1); j++){
        //         jump[j] = max(jump[j], nums[j]+jump[i]);
        //     }
        // }
        // return jump[size-1];
    }
};