class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        if(size < k){
            return -1;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        for(int i=k; i<size; i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
        
        
        
        
        
        
        
        
        
        // First Try
        // sort(nums.begin(), nums.end());
        // int len = nums.size();
        // k = len-k;
        // if(k < 0){
        //     return -1;
        // }else{
        //     return nums[k];
        // }
    }
};