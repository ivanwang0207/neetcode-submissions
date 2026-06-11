class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minIndex = 0;
        int ans = 0;

        for(int i = 1; i < prices.size(); i++){
            if (prices[i] < prices[minIndex]){
                minIndex = i;
            } else {
                ans = std::max(ans, prices[i] - prices[minIndex]);
            }
        }
        return ans;
    }
};
