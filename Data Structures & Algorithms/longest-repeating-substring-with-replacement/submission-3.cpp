class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int maxFreq = 0;
        int maxLength = 0;
        unordered_map<char, int> charIdxMap;
        for(right; right < s.size(); right++) {
            charIdxMap[s[right]]++;
            maxFreq = max(maxFreq, charIdxMap[s[right]]);

            if (right - left + 1 - maxFreq > k) {
                charIdxMap[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
