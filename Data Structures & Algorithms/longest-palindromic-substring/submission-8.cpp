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

    string longestPalindromeDST(string s) {
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

    // DP solution
    string longestPalindrome(string s) {
        int maxLength = 1;
        int startIdx = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));

        // odd base case
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        
        // even base case
        for(int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                startIdx = i;
                maxLength = 2;
            }
        }

        // expanding the length from 3 to s.size()
        for(int l = 3; l <= s.size(); l++) {
            for(int i = 0; i < s.size() - l + 1; i++) {
                if (s[i] == s[i + l - 1] && dp[i + 1][i + l - 2]) {
                    dp[i][i + l - 1] = 1;
                    if (l > maxLength){
                        maxLength = l;
                        startIdx = i;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLength);
    }
};
