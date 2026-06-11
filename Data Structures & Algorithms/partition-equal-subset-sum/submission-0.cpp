class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sum up all nums and divided by 2
        int n = nums.size();
        int target = accumulate(begin(nums), end(nums), 0);
        if (target % 2 > 0) return 0;

        target /= 2;
        // dp[j] 表示是否可以用 nums 中的一些數字組成總和為 j 的子集合
        vector<bool> dp(target + 1, 0);
        dp[0] = 1; // 因為空子集的和總是 0
        sort(nums.begin(), nums.end());

        for(int num : nums) {
            for(int i = target; i >= num; i--){
                // if dp[i-num] is true, meaning the previous nums can formulate the subset 
                // that summed up as i-num.
                // thus, we can get the subset that also includes num, 
                // in which the digits summed up as i
                if (dp[i - num])
                    dp[i] = 1;
            }
        }
        return dp[target];
    }
};