class UndergroundSystem {
    unordered_map<int, pair<string, int>> start;
    unordered_map<string, pair<long long, int>> average;
    
public:
    UndergroundSystem() {
        start.clear();
        average.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(start.find(id) != start.end()){
            return ;
        }
        start[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& name_time = start[id];
        string startStation = name_time.first;
        int startTime = name_time.second;
        string ans = startStation + "-" + stationName;
        int time = t-startTime;
        
        if(average.find(ans) != average.end()){
            auto& times = average[ans];
            times.first += time;
            times.second++;
        }else{
            average[ans] = {time, 1};
        }
        start.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation + "-" + endStation;
        auto& times = average[s];
        double ans = (double)times.first/(double)times.second;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */