class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagramMap;

        // O(m x nlogn)
        for(const string& s : strs) {
            string sorted = s;
            std::sort(sorted.begin(), sorted.end());
            anagramMap[sorted].push_back(s);
        }

        vector<vector<string>> results;
        for (auto& [key, group] : anagramMap) {
            results.push_back(group);
        }

        return results;
    }
};
