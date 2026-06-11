class Solution {

private:
    int backTracking(vector<int>& coins, int amount, vector<int>& mems) {

        // return condition: when the amount has been subtracted to zero
        if (amount == 0) { return 0; } 
        if (amount < 0) {return INT_MAX; }

        if (mems[amount] != -1) return mems[amount];

        // if the amount != 0, keep substact it by denominations
        int tmpCount = INT_MAX;
        for(const auto& c : coins) {
            int res = backTracking(coins, amount - c, mems);
            if (res != INT_MAX)
                tmpCount = min(tmpCount, res + 1);
        }

        return mems[amount] = tmpCount;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mems(amount + 1, -1);

        int minCount = backTracking(coins, amount, mems);
        return minCount != INT_MAX ? minCount : -1;
    }
};
