class Solution {

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); i++) {

            for(const auto& w : wordDict) {

                if (i + w.size() - 2 > s.size()) continue;
                
                if (dp[i - 1] && s.substr(i - 1, w.size()) == w){
                    dp[i - 1 + w.size()] = 1;
                    if (dp[s.size()] == 1) return 1;
                }
            }
        }
        return 0;
    }
};
