class Solution {
public:

    int rsearch(vector<int>& nums, int target, int l, int h){
        if (l > h) return -1;
        
        int mid = (l + h) / 2;
        if (nums[mid] == target) return mid;

        if (target < nums[mid]){
            // left ascending
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target)
                    return rsearch(nums, target, l, mid - 1);
                else 
                    return rsearch(nums, target, mid + 1, h);
            // right ascending
            } else {
                return rsearch(nums, target, l, mid - 1);
            }

        } else {
            // right ascending
            if (nums[mid] <= nums[h]) {
                if (target <= nums[h])
                    return rsearch(nums, target, mid + 1, h);
                else 
                    return rsearch(nums, target, l, mid - 1);
            // left ascending
            } else {
                return rsearch(nums, target, mid + 1, h);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        int length = nums.size();
        return rsearch(nums, target, 0, length - 1);
    }
};
