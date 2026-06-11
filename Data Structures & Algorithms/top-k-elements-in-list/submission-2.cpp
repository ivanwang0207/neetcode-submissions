class Solution {
public:

    // Min heap:: O(nlogk)
    // use a min heap, pop elements when count of nodes > k 
    // the element with the smallest frequency stays at the top will be popped out
    // the remaining k elements in the min heap are those with the largest frequency
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;

        // Step 1: count frequency using a hashmap O(n) 
        for(auto& i : nums) {
            freq[i]++;
        }

        // pass cmp into constructor
        // And use decltype(cmp) as type
        // Comparator returns true when order is wrong
        auto cmp = [](const pair<int,int>& a,
                      const pair<int,int>& b) {
            return a.second > b.second;
        };
        
        // Step 2: min heap 
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
            // decltype(cmp)
        > pq;
        
        
        for(auto& [elem, count] : freq) {
            pq.push({count, elem});
            // if the size of pq exceeds k, pop the top from the heap
            // the element with smaller occurence is popped out
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Step 3. Add elements to res
        vector<int> res;
        res.reserve(k);
        for(int i = 0; i < k; ++i){
            res.emplace_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
