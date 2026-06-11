class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        
        for(int i = 1; i < dp.size(); i++) {
            for(auto& c : coins) {
                if (i - c >= 0 && dp[i - c] != -1) {
                    int tempCount = dp[i - c] + 1;
                    if (dp[i] == -1){
                        dp[i] = tempCount;
                    } else {
                        dp[i] = std::min(tempCount, dp[i]);
                    }
                }
            }
        }
        return dp[amount];
    }
};
