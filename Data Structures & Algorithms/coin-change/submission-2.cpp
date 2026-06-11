class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for(int i = 0; i < dp.size(); i++) {
            int min_count = INT_MAX;
            for(auto& c : coins){
                if(i - c >= 0 && dp[i - c] != -1) {
                    min_count = min(min_count, dp[i - c] + 1);
                }
            }
            if (min_count != INT_MAX)
                dp[i] = min_count;
        }
        return dp[amount];
    }
};
// naive solution: Greedy + backtracking
// 1. sort the coins in descending order
// 2. start with the largest domination
// 3. try to take as many of that coin as possible
// 4. For the remaining amount:
//    Recursively try to form it using the same coin (if possible), or
//    Move to the next smaller coin if the current one is too large.
// 5. If a combination exactly matches the amount, record the number of coins.
// 6. Explore different combinations and return the minimum number of coins found.
// time complexity: O(n^(amount/min(coin)))
