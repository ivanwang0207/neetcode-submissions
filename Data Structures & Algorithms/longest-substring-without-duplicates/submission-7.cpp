class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        std::unordered_set<char> charSet;

        for(; right < s.size(); ++right) {
            const char& curChar = s[right];

            if (charSet.find(curChar) == charSet.end()) {
                maxLength = std::max(maxLength, right - left + 1);
            }
            else {
                while(charSet.count(curChar)) {
                    charSet.erase(s[left++]);
                }
            }
            charSet.insert(curChar);
        }
        return maxLength;
    }
};
