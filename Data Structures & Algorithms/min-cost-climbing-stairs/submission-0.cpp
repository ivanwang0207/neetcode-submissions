class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size(), 0);

        dp[0] = cost[0];
        dp[1] = cost[1];
        if (cost.size() < 3) 
            return std::min(dp[0], dp[1]);

        dp[2] = cost[2] + std::min(dp[0], dp[1]);

        for(int i = 3; i < n; i++){
            dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
        }
        return std::min(dp[n - 1], dp[n - 2]);
    }
};