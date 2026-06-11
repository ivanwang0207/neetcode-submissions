class Solution {

public: 
    int lengthOfLongestSubstring(std::string s) {
        int left = 0;
        std::unordered_map<char, int> charInWindow;
        int maxLength = 0;
        
        for(int right = 0; right < s.size(); right++) {
            const char& rc = s[right];
            charInWindow[rc]++;
            
            // check if duplicate occurs in current substring
            // if yes, iteratively remove left char until duplicates is removed
            while (charInWindow[rc] > 1) {
                charInWindow[s[left]]--;
                left++;
            }
            
            // update the maxLength by current substring size
            maxLength = std::max(right - left + 1, maxLength);
        }
        return maxLength;
    }
};
