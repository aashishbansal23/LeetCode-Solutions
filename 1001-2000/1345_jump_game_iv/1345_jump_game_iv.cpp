class Solution {
public:
    int minJumps(vector<int>& arr) {
        int size = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i=size-1; i>=0; i--){
            mp[arr[i]].push_back(i);
        }
        vector<bool> visited(size, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            while(s > 0){
                int node = q.front();
                q.pop();
                if(node == size-1){
                    return ans;
                }
                vector<int>& neighbours = mp[arr[node]];
                if(node-1 >= 0){
                    neighbours.push_back(node-1);
                }
                if(node+1 < size){
                    neighbours.push_back(node+1);
                }
                for(auto neighbour:neighbours){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
                neighbours.clear();
                s--;
            }
            ans++;
        }
        return size-1;
    }
};