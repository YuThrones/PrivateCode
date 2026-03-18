class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                if (i == 0 || s[i - 1] == '0') {
                    ++cnt;
                }
            }
            if (cnt > 1) {
                return false;
            }
        }
        return true;
    }
};