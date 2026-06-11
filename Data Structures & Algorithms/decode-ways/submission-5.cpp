class Solution {
public:

    // decisionTree
    int dfs(const string& s, int i, vector<int>& memo) {

        if (i == s.size()){
            return 1;
        }

        if (s[i] == '0') return 0;

        if (memo[i] != -1) return memo[i];

        // check the current 1 or 2 digits is within 1~26
        int paths = dfs(s, i+1, memo);
            
        // check whether 2 digits is available
        if (i + 1 < s.size()) {
            int digit = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (digit > 0 && digit <= 26){
                paths += dfs(s, i+2, memo);
            }
        }

        memo[i] = paths; // store path counts at i to memo[i]
        return paths;
    }

    int numDecodingsDT(string s) {
        vector<int> memo(s.size(), -1);
        int paths = dfs(s, 0, memo);
        return paths;
    }

    int numDecodingsDP(const string& s){
        int n = s.size();
        vector<int> dp(n + 1, 0);

        if (n == 0) return 1;
        if (s[0] - '0' == 0) return 0;

        dp[0] = 1; // empty string
        dp[1] = 1; // check wether the first char is 0
        for(int i = 2; i < dp.size(); i++) {

            if (s[i - 1] - '0' != 0){
                dp[i] += dp[i - 1];
            }
            
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit <= 26 && twoDigit >= 10){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }

    int numDecodings(string s) {
        return numDecodingsDP(s);
    }
};