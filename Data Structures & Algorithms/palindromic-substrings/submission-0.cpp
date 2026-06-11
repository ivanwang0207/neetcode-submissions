class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int counter = 0;

        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){

                if (s[i] == s[j]){

                    if (j - i < 2){
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }

                    if (dp[i][j])
                        counter++;
                }
            }
        }
        return counter;
    }
};
