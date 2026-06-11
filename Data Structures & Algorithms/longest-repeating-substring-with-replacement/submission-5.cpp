class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        int maxFreq = 0;
        int maxLength = 0;
        std::unordered_map<int, int> freq;

        for(; r < s.size(); ++r) {
            freq[s[r]]++;
            maxFreq = std::max(maxFreq, freq[s[r]]);

            if (r - l + 1 - maxFreq <= k) {
                maxLength = std::max(maxLength, r - l + 1);
            } else {
                freq[s[l]]--;
                l++;
            }
        }
        return maxLength;
    }
};
