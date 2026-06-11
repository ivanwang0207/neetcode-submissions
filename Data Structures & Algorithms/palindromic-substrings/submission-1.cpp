class Solution {
public:

    void expand(const string& s, int left, int right, int& counter) {
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            counter++;
            left--;
            right++;
        }
    }

    int countSubstrings(string s) {
        int counter = 0;
        for(int i = 0; i < s.size(); i++) {
            // odd-length
            expand(s, i, i, counter);
            // even-length
            expand(s, i, i+1, counter);
        }
        return counter;
    }
};
