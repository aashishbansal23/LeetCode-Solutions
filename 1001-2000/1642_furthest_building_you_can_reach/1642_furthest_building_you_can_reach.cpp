class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int size = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1; i<size; i++){
            if(heights[i] > heights[i-1]){
                int diff = heights[i]-heights[i-1];
                if(ladders > 0){
                    pq.push(diff);
                    ladders--;
                }else if(bricks > 0){
                    int brick = diff;
                    if(pq.size()>0 && diff>pq.top()){
                        brick = pq.top();
                        pq.pop();
                        pq.push(diff);
                    }
                    if(bricks-brick >= 0){
                        bricks -= brick;
                    }else{
                        return i-1;
                    }
                }else{
                    return i-1;
                }
            }
        }
        return size-1;
    }
};