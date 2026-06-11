class Solution {

private:
    void palindromeCounter(const string& s, int l, int r, int& count) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }

public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            // odd case
            int l = i, r = i;
            palindromeCounter(s, l, r, count);
            // even case
            l = i, r = i + 1;
            palindromeCounter(s, l, r, count);
        }
        return count;
    }
};
