class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        const string space = ",";

        auto it = strs.begin();
        while(it != strs.end()) {
            string count = std::to_string(it->size());
            encodedString.append(count + space + *(it));
            it++;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        std::vector<string> result;
        size_t start = 0, pos = 0;

        while((pos = s.find(",", start)) != std::string::npos) {
            int length = std::stoi(s.substr(start, pos - start));
            result.push_back(s.substr(pos + 1, length));
            start = pos + 1 + length;
        }

        return result;
    }
};
