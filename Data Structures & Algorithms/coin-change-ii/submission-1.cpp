class Solution {
public:

    int dfs(vector<int>& coins, int index, int amount, vector<vector<int>>& mems) {
        
        if (amount == 0) {
            return 1;
        }

        if (amount < 0) {
            return 0;
        }

        if (index >= coins.size()) {
            return 0;
        }

        if (mems[index][amount] != -1)
            return mems[index][amount];

        int res = 0;
        if (amount >= coins[index]) {
            res = dfs(coins, index + 1, amount, mems); // skip the current, take the next denomination
            res += dfs(coins, index, amount - coins[index], mems); // take the current denomination
        }
        return mems[index][amount] = res;
    }

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());

        vector<vector<int>> mems(
            coins.size(),
            vector<int>(amount + 1, -1)
        );

        int count = dfs(coins, 0, amount, mems);
        return count;
    }
};
