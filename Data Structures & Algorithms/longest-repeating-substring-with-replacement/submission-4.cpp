class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freq;
        int maxFreq = 0;
        int maxLength = 0;
        int l = 0, r = 0;

        for(int r = 0; r < s.size(); ++r) {
            freq[s[r]]++;
            maxFreq = std::max(maxFreq, freq[s[r]]);
            int currLength = r - l + 1;

            if(currLength - maxFreq <= k) {
                maxLength = std::max(maxLength, currLength);
            } else {
                freq[s[l]]--;
                l++;
            }
        }
        return maxLength;
    }
};
