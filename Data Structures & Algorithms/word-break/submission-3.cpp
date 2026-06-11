class Solution {

private:
    bool dfs(string& s, int startIdx, vector<string>& wordDict, vector<int>& memo) {
        
        if (startIdx == s.size()) return 1;

        if (memo[startIdx] != -1) return memo[startIdx];
        
        for (string& w : wordDict) {
            int w_size = w.size();

            if (startIdx + w_size > s.size()) continue;

            if (s.substr(startIdx, w_size) == w) {
                if (dfs(s, startIdx + w_size, wordDict, memo)){
                    return memo[startIdx] = 1;
                }
            }
        }
        return memo[startIdx] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return dfs(s, 0, wordDict, memo);
    }
};
