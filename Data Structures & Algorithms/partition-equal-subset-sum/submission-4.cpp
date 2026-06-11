class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(begin(nums), end(nums), 0);
        if (target % 2 > 0) return 0;

        target /= 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int num : nums) {
            for(int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
