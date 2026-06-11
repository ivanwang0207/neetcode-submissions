class Solution {
public:

    int rsearch(vector<int>& nums, int l, int h, int target) {
        int mid = l + (h - l) / 2;
        
        if (l > h) {
            return -1;
        }
        
        if (nums[mid] == target) {
            return mid;
        } 
        
        // if the right part is sorted
        if (nums[mid] < nums[h]) {
            if (nums[mid] < target && nums[h] >= target) {
                return rsearch(nums, mid + 1, h, target);
            } else {
                return rsearch(nums, l, mid - 1, target);
            }
         // if the left part is sorted
        } else {
            if (nums[mid] > target && nums[l] <= target) {
                return rsearch(nums, l, mid - 1, target);
            } else {
                return rsearch(nums, mid + 1, h, target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return rsearch(nums, 0, nums.size() - 1, target);
    }
};
