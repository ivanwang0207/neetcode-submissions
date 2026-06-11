class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> currCb;

        findCombination(nums, 0, res, currCb);
        return res; 
    }

    void findCombination(vector<int>& nums, int startId, 
        vector<vector<int>>& res, vector<int>& currCb) {
        
        res.push_back(currCb);

        for (int i = startId; i < nums.size(); i++) {
            if (i > startId && nums[i] == nums[i - 1])
                continue;
            
            currCb.push_back(nums[i]);
            findCombination(nums, i + 1, res, currCb);
            currCb.pop_back();
        }
    }
};

// time: (2^n * n) : n power of 2 times n, namely, 2 to the nth power times n
// space: (2^n * n) : n power of 2 times n