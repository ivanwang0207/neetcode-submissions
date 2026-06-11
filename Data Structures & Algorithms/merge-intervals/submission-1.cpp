class Solution {

private:
    bool isOverlap(const std::vector<int>& a, const std::vector<int>& b) {
        return !(a[1] < b[0] || b[1] < a[0]);
    }

    vector<int> mergeIntervals(const std::vector<int>& a, const std::vector<int>& b) {
        return vector<int>({
            std::min(a[0], b[0]),
            std::max(a[1], b[1])
        });
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> results;
        results.reserve(intervals.size());

        // sort the intervals in an ascending order
        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                    if (a[0] != b[0]) {
                        return a[0] < b[0];
                    } else{
                        return a[1] < b[1];
                    }
                  });

        results.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            auto& last = results.back();
            const auto& curr = intervals[i];

            if (isOverlap(last, curr)) {
                // last = mergeIntervals(last, curr);
                last[1] = std::max(last[1], curr[1]);

            } else {
                results.push_back(curr);
            }
        }
        return results;
    }
};
