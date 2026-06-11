class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            
            // ignore the duplicate elements
            if (i > 0 && (nums[i] == nums[i - 1]))
                continue;

            int j = i + 1;
            int k = nums.size() - 1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // ignore the duplicate elements
                    while(nums[j] == nums[j - 1]) j++;
                    while(nums[k] == nums[k + 1]) k--;

                } else if (sum < 0){
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};
