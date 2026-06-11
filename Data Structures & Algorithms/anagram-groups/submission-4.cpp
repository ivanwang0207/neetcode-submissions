class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> groups;
        std::vector<std::vector<string>> results;

        for(const auto& s : strs) {
            vector<int> count(26, 0);
            for(const auto& c : s) {
                count[c - 'a']++;
            }

            // build key
            std::string key;
            for(auto& t : count) {
                key += (std::to_string(t) + '#');
            }

            groups[key].push_back(s);
        }

        results.reserve(groups.size());
        for(auto& [_, sublist] : groups) {
            results.push_back(std::move(sublist));
        }

        return results;
    }

    // time complexity: O(n * m)
    // space complexity: O(n)
};
