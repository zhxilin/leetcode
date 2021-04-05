//1396. Design Underground System
class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mxPassengers[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int cost = t - mxPassengers[id].second;
        string path = mxPassengers[id].first + "->" + stationName;
        mxPassengers.erase(id);
        
        mxStations[path].first += cost;        
        mxStations[path].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "->" + endStation;
        return mxStations[path].first / mxStations[path].second;
    }

private:   
    unordered_map<int, pair<string,int>> mxPassengers;
    unordered_map<string, pair<double,int>> mxStations;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */