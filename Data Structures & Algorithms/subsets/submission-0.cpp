class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSubSet = vector<int>();
        findSubsets(nums, 0, currSubSet, ans);
        return ans;
    }

    void findSubsets(vector<int>& nums, int startId, vector<int>& currSubset, vector<vector<int>>& ans) {
        
        ans.push_back(currSubset);
        for(int i = startId; i < nums.size(); i++) {
            currSubset.push_back(nums[i]);
            findSubsets(nums, i + 1, currSubset, ans);
            currSubset.pop_back();
        }
    }
};

// time: O(2^n * n) -> 2^n subsets, for each set it will take up to O(n) for the recusrion stack 
// space: O(2^n * n)