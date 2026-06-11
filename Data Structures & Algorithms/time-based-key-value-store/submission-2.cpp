class TimeMap {

private:
    unordered_map<string, vector<pair<string, int>>> dict;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back(std::pair<string, int>(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if(dict.find(key) == dict.end()) {
            return "";
        }

        auto& values = dict[key];

        auto it = upper_bound(values.begin(), values.end(), timestamp,
            [](int t, const pair<string,int>& p) {
                return t < p.second;
            });

        
        if (it == values.begin()) return "";
        --it;
        return it->first;

        // int l = 0, r = values.size() - 1;
        // string result = "";

        // while(l <= r) {
        //     int mid = l + (r - l) / 2;
        //     if (values[mid].second == timestamp)
        //         return values[mid].first;

        //     if (values[mid].second < timestamp) {
        //         result = values[mid].first;
        //         l = mid + 1;
        //     } else {
        //         r = mid - 1;
        //     }
        // }
        // return result;
    }
};
