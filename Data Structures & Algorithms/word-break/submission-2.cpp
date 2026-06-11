class Solution {

private:
    bool dfs(const string& s, const vector<string>& wordDict, int idx,
             vector<int>& memo) {
        
        if (idx == s.size()) return true;
        if (memo[idx] != -1) return memo[idx];

        for(const auto& w : wordDict) {
            if (idx + w.size() > s.size()) continue;
            
            int succ = true;
            for(int i = 0; i < w.size(); i++){
                if (s[idx + i] != w[i]){
                    succ = false;
                    break;
                }
            }
            if (succ && dfs(s, wordDict, idx + w.size(), memo)) {
                return memo[idx] = 1;
            }
        }
        return memo[idx] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // naive solution: O(m * n * t) -> inefficiency

        // decision tree (dfs) + memorization
        vector<int> memo(s.size(), -1);
        return dfs(s, wordDict, 0, memo);
    }
};
