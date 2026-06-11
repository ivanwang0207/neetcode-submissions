class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxCount = 0;
        int maxLength = 0;
        int left = 0, right = 0;
        unordered_map<int, int> freq;

        while(right < s.size()){
            freq[s[right] - 'A']++;
            maxCount = std::max(maxCount, freq[s[right] - 'A']);

            if(maxCount + k > maxLength){
                maxLength = right - left + 1;
            } else {
                freq[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return maxLength;
    }
};
