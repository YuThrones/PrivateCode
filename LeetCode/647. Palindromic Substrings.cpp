class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.length();
        for (int i = 2; i <= s.length(); ++i) {
            for (int j = 0; i + j <= s.length(); ++j) {
                bool ok = true;
                for (int k = 0; k < i / 2; ++k) {
                    if (s[j + k] != s[j + i - k - 1]) {
                        ok = false;
                    }
                }
                if (ok) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};