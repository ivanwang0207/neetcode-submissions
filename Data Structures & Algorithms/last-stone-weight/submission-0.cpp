class Solution {
private:

public:
    int lastStoneWeight(vector<int>& stones) {
        // directly build max heap using begin() and end()
        std::priority_queue<int> q(stones.begin(), stones.end()); 
        
        while(q.size() > 1) {
            int l1 = q.top(); q.pop(); // O(1) + O(logN)
            int l2 = q.top(); q.pop();

            if (l1 > l2) 
                q.push(l1 - l2); // O(logN)
        }

        return q.empty() ? 0 : q.top();
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)