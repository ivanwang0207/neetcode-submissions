class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        string space = "_";

        for(string& s : strs){
            string count = to_string(s.size());
            encodedString.append(count + space + s);
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        int i = 0;
        char space = '_';

        while(i < s.size()){
            int j = i;
            while(s[j] != space) j++;

            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            decodedStrings.emplace_back(str);
            i = j + 1 + length;
        }

        return decodedStrings;
    }
};
