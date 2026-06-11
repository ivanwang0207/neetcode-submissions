class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        vector<vector<string>> res;

        // Precompute palindromic substrings using dynamic programming
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i < 2) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j]) {
                    string sub = s.substr(i, j - i + 1);
                }
            }
        }

        // backtracking execution
        vector<string> currCb;
        findCombination(s, 0, dp, currCb, res);
        return res;
    }

    void findCombination(string s, int currIndex, vector<vector<bool>>& dp,
        vector<string>& currCb, vector<vector<string>>& res) {
        
        // Base case: If we reach the end of the string, add the current partition to the result
        if (currIndex == s.size()) {
            res.push_back(currCb);
            return;
        }

        // Explore all possible partitions starting from 'start'
        for (int end = currIndex; end < s.size(); end++) {
            if (dp[currIndex][end]) { // Check if the substring s[start:end+1] is a palindrome
                currCb.push_back(s.substr(currIndex, end - currIndex + 1)); // Add the palindrome to the current partition
                findCombination(s, end + 1, dp, currCb, res); // Recur for the next substring
                currCb.pop_back(); // Backtrack
            }
        }
    }
};