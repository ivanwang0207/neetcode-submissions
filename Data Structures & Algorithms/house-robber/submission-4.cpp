class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n + 1, 0);
    //     dp[0] = 0;
    //     dp[1] = nums[0];

    //     for(int i = 2; i < n + 1; i++) {
    //         dp[i] = std::max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    //     }
    //     return dp[n];
    // }

    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;

        for (int num : nums) {
            int curr = std::max(prev2 + num, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
