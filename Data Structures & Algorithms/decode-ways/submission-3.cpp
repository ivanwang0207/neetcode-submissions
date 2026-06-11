class Solution {
public:

    // decisionTree
    int dfs(const string& s, int i, vector<int>& memo) {

        if (i == s.size()){
            return 1;
        }

        if (s[i] == '0') return 0;

        if (memo[i] != -1) return memo[i];

        // check the current 1 or 2 digits is within 1~26
        int paths = dfs(s, i+1, memo);
            
        if (i + 1 < s.size()) {
            int digit = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (digit > 0 && digit <= 26){
                paths += dfs(s, i+2, memo);
            }
        }

        memo[i] = paths;
        return paths;
    }

    int numDecodingsDT(string s) {
        vector<int> memo(s.size(), -1);
        int paths = dfs(s, 0, memo);
        return paths;
    }

    int numDecodings(string s) {
        return numDecodingsDT(s);
    }
};