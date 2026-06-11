class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;

        for(int i = 1; i < amount + 1; i++){
            int min_count = INT_MAX;

            for(const int& c : coins){
                if (i >= c && dp[i - c] != -1){
                    min_count = min(min_count, dp[i - c] + 1);
                }
            }
            dp[i] = (min_count == INT_MAX) ? -1 : min_count;
        }
        return dp[amount];
    }
};
