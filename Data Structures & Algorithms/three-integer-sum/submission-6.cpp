class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> results;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; ++i) {
            int val = nums[i];
            if (i > 0 && val == nums[i - 1]) continue;
            
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                if (nums[j] + nums[k] == -val){
                    results.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (nums[j] + nums[k] < -val) {
                    j++;
                } 
                else{
                    k--;
                }

            }
        }
        return results;
    }
};
