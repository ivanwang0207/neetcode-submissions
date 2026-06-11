class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        if (n == 1){
            return 1;
        } 
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++){
            int oneDigit = s[i - 1] - '0';
            if (oneDigit > 0 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            } 
            int twoDigits = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (twoDigits >= 10 && twoDigits <= 26){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};