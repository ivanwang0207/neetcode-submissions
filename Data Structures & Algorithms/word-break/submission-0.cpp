class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = 1;

        for(int i = 1; i < s.size() + 1; i++){

            for(int j = 0; j < wordDict.size(); j++){
                string w = wordDict[j];
                if (i >= w.size() && dp[i - w.size()] && 
                    s.substr(i - w.size(), w.size()) == w){
                    dp[i] = 1;
                }
            }
        }
        return dp[s.size()];
    }
};
