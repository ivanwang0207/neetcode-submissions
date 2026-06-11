class Solution {
public:

    int rfindMin(vector<int> &nums, int l, int h){
        if (l == h){
            return nums[l];
        }

        int mid = (l + h) / 2;
        if (nums[mid] > nums[h]){
            return rfindMin(nums, mid + 1, h);
        } else {
            return rfindMin(nums, l, mid);
        }
    }

    int findMin(vector<int> &nums) {
        int length = nums.size();
        return rfindMin(nums, 0, length - 1);
    }
};
