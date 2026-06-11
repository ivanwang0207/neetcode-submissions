class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // The key observation: anagrams share the same sorted representation
        
        // Instead of comparing every pair in brute force solution, we can use a hash map.
        // For each string, we sort it and use the sorted string as the key.
        // Then we group all original strings that have the same sorted form.
        
        std::unordered_map<string, vector<string>> anagramMap;

        // O(m x nlogn)
        /*
        I iterate through each string in the input.
        For each string, I create a sorted copy of it.
        Then I use this sorted string as a key in an unordered_map.
        The value associated with the key is a list of original strings that match this sorted form.
        */
        for(const string& s : strs) {
            string sorted = s;
            std::sort(sorted.begin(), sorted.end());
            anagramMap[sorted].push_back(s);
        }

        vector<vector<string>> results;
        results.reserve(anagramMap.size());
        for (auto& [key, group] : anagramMap) {
            results.push_back(group);
        }

        return results;
    }
};
