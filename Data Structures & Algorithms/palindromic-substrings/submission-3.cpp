class Solution {

public:
    int countSubstrings(string s) {
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length, 0));
        int count = 0;

        for(int i = 0; i < length; i++) {
            dp[i][i] = 1;
            count++;
        }

        for(int i = 0; i < length - 1; i++) {
            if (s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                count++;
            }
        }

        for(int n = 3; n <= length; n++) {
            for(int i = 0; i <= length - n; i++) {
                if (dp[i + 1][i + n - 2] && s[i] == s[i + n - 1]){
                    dp[i][i + n - 1] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
