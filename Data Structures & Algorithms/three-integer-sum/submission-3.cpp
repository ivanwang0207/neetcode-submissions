class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end()); // O(nlogn)
        
        for(int i = 0; i < nums.size() - 2; ++i) {
            
            // if current i is equal to the previous one, skip it 
            if (i > 0 && (nums[i] == nums[i - 1]))
                continue;
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            // -nums[i] = nums[j] + nums[k]
            // two pointer (opposite direction)
            while(j < k) {
                int twoSum = nums[j] + nums[k];
                
                if (twoSum == -nums[i]) {
                    results.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(nums[j] == nums[j-1]) j++;
                    while(nums[k] == nums[k+1]) k--;
                }
                else if (twoSum < -nums[i]) {
                    j++;   
                } else {
                    k--;
                }
            }
        }
        return results;
    }
};
