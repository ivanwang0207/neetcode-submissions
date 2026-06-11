class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for(int i = 1; i < dp.size(); i++) {
            int min_val = INT_MAX;
            for(auto& c : coins) {
                if (c <= i && dp[i - c] != -1) {
                    min_val = min(min_val, dp[i - c] + 1);
                }
            }

            if (min_val != INT_MAX)
                dp[i] = min_val;
        }
        return dp[amount];
    }
};
