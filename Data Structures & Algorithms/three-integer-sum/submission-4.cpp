class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results;

        for(int i = 0; i < nums.size() - 2; i++) {

            // if current i is equal to the previous one, skip it 
            if (i > 0 && (nums[i] == nums[i - 1]))
                continue;
            
            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                if (nums[l] + nums[r] == -nums[i]) {
                    results.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // ignore the duplicate elements
                    while(nums[l] == nums[l - 1]) l++;
                    while(nums[r] == nums[r + 1]) r--;
                }
                else if (nums[l] + nums[r] < -nums[i]) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return results;
    }
};
