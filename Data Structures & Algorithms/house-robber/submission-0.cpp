class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];
        if (n <= 1) return dp[1]; 

        dp[2] = max(dp[1], nums[1] + dp[0]);
        for (int i = 3; i < n + 1; i++){
            dp[i] = max(dp[i - 1], 
                nums[i - 1] + dp[i - 2]);
        }

        return max(dp[n], dp[n - 1]);
    }
};
