class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        int maxCount = dp[1];

        for(int i = 2; i < n + 1; i++){
            for(int j = i - 2; j >= 0; j--){
                if (nums[i - 1] > nums[j]){
                    dp[i] = max(dp[i], dp[j + 1] + 1);
                }
            }
            maxCount = max(maxCount, dp[i]);
        }
        return maxCount;
    }
};
