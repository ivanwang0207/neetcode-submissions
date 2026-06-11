class Solution {

private:
    int dfs(vector<int>& nums, int preIdx, int curIdx, vector<vector<int>>& memo) {
        if (curIdx == nums.size()) {
            return 0;
        }

        // check if the dfs call has been caught by memo
        if (memo[preIdx+1][curIdx] != -1) 
            return memo[preIdx+1][curIdx];
            
        int tmpLength;
        if (preIdx == -1 || nums[preIdx] < nums[curIdx]) {
            int included = 1 + dfs(nums, curIdx, curIdx+1, memo);
            int excluded = dfs(nums, preIdx, curIdx+1, memo);
            tmpLength = included > excluded ? included : excluded;
        }
        else {
            tmpLength = dfs(nums, preIdx, curIdx+1, memo);
        }

        // store curIdx and tmpLength in memo
        return memo[preIdx+1][curIdx] = tmpLength;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int preIdx = -1, curIdx = 0;
        // unordered_map<int, int> memo;
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        return dfs(nums, preIdx, curIdx, memo);
    }
};
