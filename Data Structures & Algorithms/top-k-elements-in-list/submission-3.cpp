using paired = pair<int, int>;

class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for(auto& n : nums) {
            freq[n]++;
        }

        std::priority_queue<paired, std::vector<paired>, std::greater<paired>> q;
        for(const auto& [elem, count] : freq) {
            q.push({count, elem});
            if (q.size() > k) {
                q.pop();
            }
        }

        std::vector<int> results;
        while(!q.empty()) {
            results.push_back(q.top().second);
            q.pop();
        }

        return results;
    }
};
