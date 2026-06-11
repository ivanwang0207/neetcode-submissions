class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1){
            return s[0] == '0' ? 0 : 1;
        }
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for(int i = 2; i < n + 1; i++){

            if (s[i - 1] - '0' > 0 && s[i - 1] - '0' <= 9) {
                dp[i] += dp[i - 1];
            } 
            int twoDigits = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (twoDigits >= 10 && twoDigits <= 26){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }

    // int twoDigits = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
    // if (twoDigits >= 10 && twoDigits <= 26){
    //     dp[i] += dp[i - 2];
    // }
};
