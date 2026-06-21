class Solution {
    bool static compator(vector<int>& v1, vector<int>& v2){
        if(v1[1] < v2[1]){
            return true;
        }else if(v1[1] == v2[1]){
            return v1[0]<v2[0];
        }else{
            return false;
        }
    }
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compator);
        priority_queue<vector<int>> pq;
        int size = courses.size();
        int totalTime = 0;
        for(int i=0; i<size; i++){
            if(courses[i][0] > courses[i][1]){
                continue;
            }
            if(totalTime+courses[i][0] <= courses[i][1]){
                totalTime += courses[i][0];
                pq.push(courses[i]);
            }else if(!pq.empty() && pq.top()[0]>courses[i][0]){
                totalTime -= pq.top()[0];
                pq.pop();
                totalTime += courses[i][0];
                pq.push(courses[i]);
            }
        }
        return pq.size();
    }
};