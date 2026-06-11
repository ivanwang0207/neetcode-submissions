class Solution {
public:
    // optimization: space O(1) use only res array and maintain a running suffix product
    // Instead of storing both prefix and suffix arrays,
    // we can reuse the result array to store prefix products first.
    // Then, during the backward pass, we multiply by current running suffix product. 
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // compute prefix products in forward pass
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        // multiply result array by a running suffix product in backward pass
        int suffix = 1; // running variable
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= suffix; // multiply the current result with the suffix value
            suffix *= nums[i]; // update running suffix
        }

        return res;
    }
};
