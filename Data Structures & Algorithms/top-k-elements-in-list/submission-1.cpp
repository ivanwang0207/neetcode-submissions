class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;

        // Step 1: count frequency using a hashmap O(n) 
        for(auto& i : nums) {
            freq[i]++;
        }

        // Step 2: Use bucket sort to get the top k elements: O(n)
        // The range of occurance: [0, nums.size()]
        vector<vector<int>> buckets(nums.size() + 1, vector<int>());
        for(auto& [num, count] : freq) {
            buckets[count].emplace_back(num);
        }
        
        // Step 3: iterate k times to extract the top occurance elements in buckets
        vector<int> res;
        for (int i = buckets.size()-1; i >= 0 && res.size() < k; i--) {
            for (int elem : buckets[i]) {
                res.push_back(elem);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
