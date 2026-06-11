class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sorting the candidates ascendingly
        sort(candidates.begin(), candidates.end());

        // use recursive stack to find out all candidates that sum up as target 
        vector<vector<int>> res;
        vector<int> currCb;
        findCombination(target, 0, candidates, res, currCb);
        return res;
    }

    void findCombination(const int target, int startId, 
        vector<int>& candidates, vector<vector<int>>& res, vector<int>& currCb) {
        
        int currSum = accumulate(begin(currCb), end(currCb), 0);

        if (currSum > target) 
            return;
        
        if (currSum == target) {
            res.push_back(currCb);
            return;
        }

        for(int i = startId; i < candidates.size(); i++) {

            // handle duplicate candidates
            // skip duplicates within the same level of recursion
            if (i > startId && candidates[i - 1] == candidates[i]) 
                continue;

            currCb.push_back(candidates[i]);
            findCombination(target, i + 1, candidates, res, currCb);
            currCb.pop_back();
        } 
    }
};