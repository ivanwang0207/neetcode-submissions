class Solution {
public:
    // time: O(n), space: O(n)
    vector<int> productExceptSelf(vector<int>& nums){
        // brute force solution
        // O(n^2): two nested loops: 
        // For each index i, iterate through the array again
        // and multiply all elements except nums[i]
        
        // optimize: precompute prefix and suffix products
        // create two arrays that store the product of elements from left and from right
        vector<int> prefixs(nums.size()); // stores the product of elements from index 0 to i.
        vector<int> suffixs(nums.size()); // stores the product of elements from index i to n-1

        prefixs[0] = nums[0];
        suffixs[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); ++i) {
            prefixs[i] = prefixs[i - 1] * nums[i];
            suffixs[nums.size() - 1 - i] = suffixs[nums.size() - i] * nums[nums.size() - 1 - i];
        }
        
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            int left = (i - 1 < 0) ? 1 : prefixs[i-1];
            int right = (i + 1 > nums.size() - 1) ? 1 : suffixs[i+1];
            res[i] = left * right;
        }
        
        return res;
    }
};
