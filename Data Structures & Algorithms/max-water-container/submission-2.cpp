class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxAmount = INT_MIN;

        while(left < right) {
            int amount = (right - left) * min(heights[right], heights[left]);

            maxAmount = max(maxAmount, amount);
            if (heights[right] < heights[left]) {
                right--;
            } else {
                left++;
            }
        }
        return maxAmount;
    }
};
