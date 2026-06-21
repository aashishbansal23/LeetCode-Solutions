class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        vector<bool> visited(size, false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            start = q.front();
            q.pop();
            if(arr[start] == 0){
                return true;
            }
            if(start+arr[start]<size && !visited[start+arr[start]]){
                q.push(start+arr[start]);
                visited[start+arr[start]] = true;
            }
            if(start-arr[start]>=0 && !visited[start-arr[start]]){
                q.push(start-arr[start]);
                visited[start-arr[start]] = true;
            }
        }
        return false;
    }
};