class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currCb;
        vector<bool> visited = vector<bool>(nums.size(), 0);

        findCombination(nums, visited, res, currCb);
        return res;
    }

    void findCombination(vector<int>& nums, vector<bool>& visited,
        vector<vector<int>>& res, vector<int>& currCb) {

        // return the function while the size reaches the max size,
        // also push the current combination to the result
        if (currCb.size() == nums.size()){
            res.push_back(currCb);
            return;
        }

        // if the currCb has not reached the max size, 
        // iterate through nums and find the element in the next layer
        // the element that is marked as visited will not be used in the next layer
        for(int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            currCb.push_back(nums[i]);
            visited[i] = 1;
            findCombination(nums, visited, res, currCb);
            currCb.pop_back();
            visited[i] = 0;
        }
    }
};

// time complextiy: O(n! * n) -> factorial of n times n
// space complextiy: O(n! * n) + O(n)
