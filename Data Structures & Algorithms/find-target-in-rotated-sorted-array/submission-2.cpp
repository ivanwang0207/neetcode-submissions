class Solution {
public:

    int rsearch(vector<int>& nums, int target, int l, int h){
        if (l > h)
            return -1;
        
        int mid = (l + h) / 2;
        if (nums[mid] == target)
            return mid;

        // right part is ascending
        if (nums[l] <= nums[mid]){
            if (nums[l] <= target && target < nums[mid]){
                return rsearch(nums, target, l, mid - 1);
            } else {
                rsearch(nums, target, mid + 1, h);
            }
        } else if (nums[h] >= nums[mid]) {
            if (nums[mid] < target && target <= nums[h]){
                return rsearch(nums, target, mid + 1, h);
            } else {
                rsearch(nums, target, l, mid - 1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        int length = nums.size();
        return rsearch(nums, target, 0, length - 1);
    }
};
