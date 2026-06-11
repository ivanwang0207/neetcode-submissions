class Solution {
public:
    int robDP(vector<int>& nums) {
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

    // iterative: bottom-up
    int robIter(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for(int num : nums) {
            int curr = max(prev2 + num, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    // recursive + memoization: top-down
    int dfs(vector<int>& nums, vector<int>& mems, int i) {
        if (i >= nums.size()) return 0;

        if (mems[i] != -1) return mems[i];        

        int next2 = dfs(nums, mems, i + 2);
        int next1 = dfs(nums, mems, i + 1);
        mems[i] = max(nums[i] + next2, next1);

        return mems[i];
    }

    int rob(vector<int>& nums) {
        vector<int> mems(nums.size(), -1);
        return dfs(nums, mems, 0);
    }
};
