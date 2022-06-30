class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity > jug1Capacity+jug2Capacity){
            return false;
        }
        set<int> visited;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(x == targetCapacity){
                return true;
            }
            if(x+jug1Capacity<=jug1Capacity+jug2Capacity && visited.count(x+jug1Capacity)==0){
                q.push(x+jug1Capacity);
                visited.insert(x+jug1Capacity);
            }
            if(x-jug1Capacity>=0 && visited.count(x-jug1Capacity)==0){
                q.push(x-jug1Capacity);
                visited.insert(x-jug1Capacity);
            }
            if(x+jug2Capacity<=jug1Capacity+jug2Capacity && visited.count(x+jug2Capacity)==0){
                q.push(x+jug2Capacity);
                visited.insert(x+jug2Capacity);
            }
            if(x-jug2Capacity>=0 && visited.count(x-jug2Capacity)==0){
                q.push(x-jug2Capacity);
                visited.insert(x-jug2Capacity);
            }
        }
        return false;
    }
};