class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n + 1, 0);
        vector<int> dpMin(n + 1, 0);

        int result = INT_MIN;

        dpMax[0] = 1;
        dpMin[0] = 1;
        for(int i = 1; i < n + 1; i++){
            dpMax[i] = max(max(nums[i - 1], nums[i - 1] * dpMax[i - 1]), nums[i - 1] * dpMin[i - 1]);
            dpMin[i] = min(min(nums[i - 1], nums[i - 1] * dpMin[i - 1]), nums[i - 1] * dpMax[i - 1]);

            result = max(result, dpMax[i]);
        }
        return result;
    }
};
