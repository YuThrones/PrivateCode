class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v1;
        split(s1, v1);
        split(s2, v1);
        vector<string> result;
        for (string str : v1) {
            if (count(v1.begin(), v1.end(), str) == 1) {
                result.push_back(str);
            }
        }
        return result;
    }

    void split(string& s, vector<string>& v) {
        int index = 0;
        int start = 0;
        while(index < s.length()) {
            if (s[index] == ' ') {
                if (index > start) {
                    v.push_back(s.substr(start, index - start));
                }
                start = index + 1;
            }
            ++index;
        }
        if (index > start) {
            v.push_back(s.substr(start, index - start));
        }
    }
};