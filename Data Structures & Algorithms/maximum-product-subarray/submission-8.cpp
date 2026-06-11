class Solution {
public:
    int maxProductDP(vector<int>& nums) {
        vector<int> dp_min(nums.size() + 1, 1);
        vector<int> dp_max(nums.size() + 1, 1);
        int res = INT_MIN;

        for(int i = 1; i < dp_min.size(); i++) {
            dp_min[i] = min(min(dp_min[i - 1] * nums[i - 1], dp_max[i - 1] * nums[i - 1]), nums[i - 1]);
            dp_max[i] = max(max(dp_min[i - 1] * nums[i - 1], dp_max[i - 1] * nums[i - 1]), nums[i - 1]);
            res = max(dp_max[i], res);
        }
        return res;
    }



    int maxProduct(vector<int>& nums) {
        int subMax = nums[0];
        int subMin = nums[0];
        int res = subMax;

        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                subMax = max(subMax * nums[i], nums[i]);
                subMin = min(subMin * nums[i], nums[i]);
            } else {
                int tempMax = subMax;
                subMax = max(subMin * nums[i], nums[i]);
                subMin = min(tempMax * nums[i], nums[i]);
            }
            res = max(subMax, res);
        }
        return res;
    }
};
