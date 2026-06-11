class Solution {
public:
    int maxProductDP(vector<int>& nums) {
        vector<int> dp_max(nums.size() + 1, 1);
        vector<int> dp_min(nums.size() + 1, 1);
        int max_res = INT_MIN;

        for(int i = 1; i < dp_max.size(); i++) {
            if (nums[i - 1] > 0){
                dp_max[i] = std::max(nums[i - 1], nums[i - 1] * dp_max[i - 1]);
                dp_min[i] = std::min(nums[i - 1], nums[i - 1] * dp_min[i - 1]);
            } else {
                dp_max[i] = std::max(nums[i - 1], nums[i - 1] * dp_min[i - 1]);
                dp_min[i] = std::min(nums[i - 1], nums[i - 1] * dp_max[i - 1]);
            }
            max_res = std::max(dp_max[i], max_res);
        }

        return max_res;
    }

    int maxProduct(vector<int>& nums) {
        int max_subarr = nums[0];
        int min_subarr = nums[0];
        int max_res = max_subarr;

        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0){
                max_subarr = std::max(nums[i], max_subarr * nums[i]);
                min_subarr = std::min(nums[i], min_subarr * nums[i]);
            } else {
                int temp = max_subarr;
                max_subarr = std::max(nums[i], min_subarr * nums[i]);
                min_subarr = std::min(nums[i], temp * nums[i]);
            }
            max_res = std::max(max_subarr, max_res);
        }

        return max_res;
    }
};
