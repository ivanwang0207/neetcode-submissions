// 153. Find Minimum in Rotated Sorted Array
class Solution {
  
private:
    int rfindMin(vector<int> &nums, int l, int h){
        int mid = l + (h - l) / 2;
        
        if (l == h) {
            return nums[l];
        }
        // find the part of array where the rotation occurs
        if (nums[mid] < nums[h]) {
            return rfindMin(nums, l, mid);
        } else {
            return rfindMin(nums, mid + 1, h);
        }
    }
    
    int rfindMinIter(vector<int> &nums){
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if (l == h){
                return nums[mid];
            }
            else if (nums[mid] < nums[h]){
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    
public:
    int findMin(vector<int>& nums, bool is_recur=true) {
        // the whole elements are in ascending order
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];
        if (is_recur){
            return rfindMin(nums, 0, nums.size() - 1);
        }
        else {
            return rfindMinIter(nums);
        }
    }
};

// int main() {
//     Solution solution;
//     vector<int> case1 = {3,4,5,6,1,2};
//     vector<int> case2 = {4,5,0,1,2,3};
//     vector<int> case3 = {4,5,6,7};
    
//     int result = solution.findMin(case3);
//     int result_2 = solution.findMin(case3, false);
//     std::cout << "min: " << result << std::endl;
//     std::cout << "min: " << result_2 << std::endl;
// }