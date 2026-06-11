class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int currLength = 0;

        for(int i = 0; i < s.size(); i++){
            if (!charIndexMap.count(s[i]) || charIndexMap[s[i]] < i - currLength){
                charIndexMap[s[i]] = i;
                currLength++;

                if (currLength > maxLength) 
                    maxLength = currLength;
            } else {
                currLength = i - charIndexMap[s[i]]; 
                charIndexMap[s[i]] = i;
            }
        }
        return maxLength;
    }
};
