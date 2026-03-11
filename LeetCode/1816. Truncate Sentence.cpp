class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i == s.length() - 1) {
                return s;
            }
            if (s[i] == ' ') {
                if (count == k) {
                    return s.substr(0, i);
                }
            }
            else if (i == 0 || s[i - 1] == ' ') {
                ++count;
            }
        }
        return "";
    }
};