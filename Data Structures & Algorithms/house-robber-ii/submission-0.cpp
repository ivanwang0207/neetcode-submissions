class Solution {
public:

    int helper(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        int index = start;
        vector<int> dp(n + 1, 0);
        
        dp[1] = nums[index++];
        if (n <= 1)
            return dp[1];
        dp[2] = max(nums[index++] + dp[0], dp[1]);    

        for (int i = 3; i < n + 1; i++) {
            dp[i] = max(nums[index++] + dp[i - 2], dp[i - 1]); 
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        if (nums.size() >= 2)
            return max(helper(nums, 0, nums.size() - 2),
                helper(nums, 1, nums.size() - 1));
        else
            return nums[0];
    }
};
