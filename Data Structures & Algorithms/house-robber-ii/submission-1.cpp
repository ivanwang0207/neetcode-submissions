class Solution {
public:

    int helper(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size() + 1, 0);
        dp[start] = 0;
        dp[start + 1] = nums[start];

        for(int i = start + 2; i <= end + 1; i++){
            dp[i] = std::max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[end + 1];
    }

    int rob(vector<int>& nums) {
        if (nums.size() >= 2)
            return max(helper(nums, 0, nums.size() - 2),
                helper(nums, 1, nums.size() - 1));
        else
            return nums[0];
    }
};
