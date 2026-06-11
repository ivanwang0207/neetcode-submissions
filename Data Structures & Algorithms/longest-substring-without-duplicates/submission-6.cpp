class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> charIdxMap;
        int maxLength = 0;

        for(right; right < s.size(); right++) {
            const char& c = s[right];
            charIdxMap[c]++;

            while (charIdxMap[c] > 1) {
                charIdxMap[s[left]]--;
                left++;
            }

            if (right - left + 1 > maxLength){
                maxLength = right - left + 1;
            }
        }
        return maxLength;
    }
};
