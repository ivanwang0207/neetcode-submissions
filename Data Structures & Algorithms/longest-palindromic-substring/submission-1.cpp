class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return string();
        if (n == 1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        for(int i = 0; i < n - 1; i++){
            if (s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                max_length = 2;
                start_index = i;
            }
        }

        for(int l = 3; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                if (s[i] == s[i + l - 1] && dp[i + 1][i + l - 2]){
                    dp[i][i + l - 1] = 1;
                    max_length = l;
                    start_index = i;
                }
            }
        }
        return s.substr(start_index, max_length);
    }

private:
    int start_index = 0;
    int max_length = 1;
};
