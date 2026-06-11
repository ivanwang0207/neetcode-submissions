class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> groups;

        for(const auto& s : strs) {
            string s_sorted = s; // potential type of anagram
            sort(s_sorted.begin(), s_sorted.end());
            groups[s_sorted].push_back(s);
        }

        std::vector<std::vector<string>> results;
        results.reserve(groups.size());
        for(const auto& [_, sublist] : groups) {
            results.push_back(sublist);
        }

        return results;
    }

    // time complexity: O(n * mlog(m))
    // space complexity: O(n)
};
