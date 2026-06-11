class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        pair<int, string> data = make_pair(timestamp, value);
        map[key].emplace_back(data);
    }
    
    string get(string key, int timestamp) {

        if (map.find(key) == map.end()) {
            return ""; // Key does not exist
        }

        int left = 0;
        int right = map[key].size() - 1;
        
        const auto& vec = map[key];
        string result = "";

        while(left <= right){
            int mid = left + (right - left) / 2;
            int temp_timestamp = vec[mid].first;

            if (temp_timestamp <= timestamp) {
                result = vec[mid].second;
                left = mid + 1;

            } else {
                right = mid - 1;
            }
        }
        return result;
    }

private:
    unordered_map<string, vector<pair<int, string>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */