class Solution {
public:
    int characterReplacement(string s, int k) {
        // XYYYX
        // XYYYZZ
        int left = 0;
        std::unordered_map<char, int> freq;
        int maxLength = 0;
        int maxFreq = 0;
        
        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            
            // obtain the character with the most occurence
            // actually only updates when expanding
            maxFreq = std::max(maxFreq, freq[s[right]]);
            
            // shrink if invalid window: window size - maxFreq > k
            while (right - left + 1 - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }
            
            // current maxLength will be <= maxFreq + k
            maxLength = max(maxLength, right - left + 1);
            
            // Important optimization:
            // Dont need to recompute the maxFreq because
            // what we care about is the final maxLength (maxFreq + k)
            // and care about whether the maxFreq can be expanded as the right pointer move onward
        }
        return maxLength;
    }  
};
