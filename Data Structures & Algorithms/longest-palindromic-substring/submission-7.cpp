class Solution {
public:

    void expand(string& s, int i, int j, int& startIdx, int& maxLength) {
        if (i < 0 || j >= s.size()) return;

        if (s[i] == s[j]) {
            int currLength = j - i + 1;
            if (currLength > maxLength) {
                startIdx = i;
                maxLength = currLength;
            }
        } else { return; }
        expand(s, i - 1, j + 1, startIdx, maxLength);
    }

    void expandIter(string& s, int i, int j, int& startIdx, int& maxLength) {
        while (s[i] == s[j] && i >= 0 && j < s.size()) {
            int currLength = j - i + 1;
            if (currLength > maxLength) {
                startIdx = i;
                maxLength = currLength;
            }
            i--;
            j++;
        }
    }


    string longestPalindrome(string s) {
        int maxLength = 0;
        int startIdx = 0;

        for(int i = 0; i < s.size(); i++) {
            // the expand of odd cases
            expandIter(s, i, i, startIdx, maxLength);
            // the expand of even cases
            expandIter(s, i, i+1, startIdx, maxLength);
        }
        return s.substr(startIdx, maxLength);
    }
};
