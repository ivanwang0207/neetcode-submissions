class Solution {
public:

    // int helper(vector<int>& nums, int start, int end) {
    //     vector<int> dp(nums.size() + 1, 0);
    //     dp[start] = 0;
    //     dp[start + 1] = nums[start];

    //     for(int i = start + 2; i <= end + 1; i++){
    //         dp[i] = std::max(nums[i - 1] + dp[i - 2], dp[i - 1]);
    //     }
    //     return dp[end + 1];
    // }

    int helper(vector<int>& nums, int start, int end){
        int prev2 = 0;
        int prev1 = 0;

        for(int i = start; i < end + 1; i++) {
            int curr = std::max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }


    int rob(vector<int>& nums) {
        if (nums.size() >= 2)
            return max(helper(nums, 0, nums.size() - 2),
                helper(nums, 1, nums.size() - 1));
        else
            return nums[0];
    }
};
