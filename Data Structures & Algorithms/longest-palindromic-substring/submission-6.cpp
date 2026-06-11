class Solution {

public:

    // Expand Around Center 
    // time: O(n^2), space: O(1)
    void expand(const string& s, int i, int j, int& maxLen, int& startIdx){
        
        if (i < 0 || j >= s.size() || s[i] != s[j])
            return;

        if (j - i + 1 > maxLen) {
            maxLen = j - i + 1;
            startIdx = i;
        }
        expand(s, i-1, j+1, maxLen, startIdx);
    }

    void expandIterative(const string& s, int i, int j, int& maxLen, int& startIdx){
        int left = i;
        int right = j;
        while(left >= 0 && right < s.size() && s[left]==s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIdx = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 1;
        int startIdx = 0;

        for(int i = 0; i < n; i++){
            // base case for odd-length
            expandIterative(s, i, i, maxLen, startIdx);
            // base case for even-length
            expandIterative(s, i, i+1, maxLen, startIdx);
        }
        return s.substr(startIdx, maxLen);
    }

    // DP time: O(n^2), space: O(n^2)
    string longestPalindromeDP(string s) {

        // maintain variable for maxLen and startPt
        int maxLength = 1;
        int startIdx = 0;

        // 2-DP to track the validity of palindrome with start and end points
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        // check the palindrome with len=1 (base case for odd-length)
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        // check the palindrome with len=2 (base case for even-length)
        for(int i = 0; i < n - 1; i++){
            if (s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                startIdx = i;
                maxLength = 2;
            }
        }
        
        // check the alindrome iteratively from len=3 to n
        for(int l = 3; l < n+1; l++) {
            for(int i = 0; i < n - l + 1; i++){
                if ((s[i] == s[i + l - 1]) && dp[i + 1][i + l - 2]){
                    dp[i][i + l - 1] = 1;
                    startIdx = i;
                    maxLength = l;
                }
            }
        }
        return s.substr(startIdx, maxLength);
    }
};
