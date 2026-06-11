class Solution {

private:
    bool dfs(const vector<int>& nums, int idx, 
             int remain, vector<vector<int>>& memo) {
        
        if (remain == 0) return true;
        if (idx == nums.size() || remain < 0) return false;
 
        if (memo[idx][remain] != -1) return memo[idx][remain];

        bool include = dfs(nums, idx + 1, remain - nums[idx], memo);
        bool exclude = dfs(nums, idx + 1, remain, memo);

        if (include || exclude) {
            return memo[idx][remain] = 1;
        }
        return memo[idx][remain] = 0;
    }

public:
    bool canPartition(vector<int>& nums) {
        // sum up all nums and divided by 2
        int n = nums.size();
        int target = accumulate(begin(nums), end(nums), 0);
        if (target % 2 > 0) return 0;

        target /= 2;

        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return dfs(nums, 0, target, memo);
    }
};
