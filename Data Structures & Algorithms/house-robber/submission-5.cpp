class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);

        // base cases
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(dp[1], dp[0] + nums[1]);

        for(int i = 3; i < nums.size() + 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[nums.size()]; 
    }
};
