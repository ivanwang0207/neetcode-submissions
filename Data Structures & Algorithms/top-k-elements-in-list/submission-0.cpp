class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;

        // Step 1: count frequency
        for(auto& i : nums) {
            freq[i]++;
        }

        // Step 2: max heap (pair<frequency, number>)
        priority_queue<pair<int, int>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});
        }

        // Step 3: extract top k
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};
