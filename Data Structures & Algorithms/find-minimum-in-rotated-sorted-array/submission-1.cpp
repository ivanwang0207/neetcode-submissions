class Solution {
public:

    int rfindMin(vector<int> &nums, int l, int h){
        int mid = l + (h - l) / 2;

        if (l == h) return nums[l];

        if (nums[mid] < nums[h]){
            return rfindMin(nums, l, mid);
        }
        else {
            return rfindMin(nums, mid + 1, h);
        }
    }

    int findMin(vector<int> &nums) {
        return rfindMin(nums, 0, nums.size() - 1);
    }
};
