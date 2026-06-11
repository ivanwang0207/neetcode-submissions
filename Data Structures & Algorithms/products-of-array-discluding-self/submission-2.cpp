class Solution {
public:
    // optimization: space O(1) use only res array and maintain a running suffix product
    // Instead of storing both prefix and suffix arrays,
    // we can reuse the result array to store prefix products first.
    // Then, during the backward pass, we multiply by current running suffix product. 
    vector<int> productExceptSelf(vector<int>& nums) {
        // intialize the resulting vector with n's one
        int n = nums.size();
        vector<int> res(n, 1);
        
        // estimate the running suffix product in backward pass
        for(int i = n - 1; i >= 0; --i) {
            if (i == n - 1)
                res[i] = nums[i];
            else
                res[i] = res[i + 1] * nums[i];
        }
        
        // estimate the resulting product with a running prefix variable
        int prefix = 1;
        for(int i = 0; i < n; ++i) {
            if (i == n - 1)
                res[i] = prefix;
            else
                res[i] = prefix * res[i+1];
            prefix *= nums[i]; // update prefix with current element
        }
        return res;
    }
};
