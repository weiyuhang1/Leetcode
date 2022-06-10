class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //binary search
        if (mp.find(key) == mp.end()) return "";
        int left = 0;
        int right = mp[key].size() - 1;
        if (mp[key][left].first > timestamp) return "";
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mp[key][mid].first == timestamp) {
                return mp[key][mid].second;
            } else if (mp[key][mid].first < timestamp) {
                left = mid;
            } else {
                right = mid - 1;
            }
            if (right - left == 1) {
                return mp[key][right].first <= timestamp ? mp[key][right].second : mp[key][left].second;
            }
        }
        return mp[key][right].second;
    }
private:
    unordered_map<string, vector<pair<int, string>>> mp;
    
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */