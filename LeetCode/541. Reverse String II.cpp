class Solution {
    public:
        string reverseStr(string s, int k) {
            for (int i = 0; i < s.length(); i += 2 * k) {
                int end = min(i + k, int(s.length()));
                for (int j = 0; j < (end - i) / 2; ++j) {
                    swap(s[i + j], s[end - j - 1]);
                }
            }
            return s;
        }
    };