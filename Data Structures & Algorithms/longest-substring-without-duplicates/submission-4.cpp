class Solution {

public: 
    int lengthOfLongestSubstring(std::string s) {
        int left = 0, right = 0;
        std::unordered_set<char> charInWindow;
        int maxLength = 0;
        
        while (right < s.size()) {
            const char& rc = s[right];
            // if s[right] is not in the set, add it directly
            if (!charInWindow.count(rc)) {
                charInWindow.insert(rc);
                // update the max length
                if (charInWindow.size() > maxLength) {
                    maxLength = charInWindow.size();
                }
                right++;
            } else {
                // iterate left through the string until the duplicate is removed
                while (charInWindow.count(rc)) {
                    const char& lc = s[left++];
                    charInWindow.erase(lc);
                }
            }
        }
        return maxLength;
    }
};
