class Solution {
public:
    int minOperations(string s) {
        int ans = s.length();
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i % 2 == 0 && s[i] != '0') {
                ++count;
            }
            else if (i % 2 == 1 && s[i] != '1') {
                ++count;
            }
        }
        ans = min(count, ans);
        count = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i % 2 == 0 && s[i] != '1') {
                ++count;
            }
            else if (i % 2 == 1 && s[i] != '0') {
                ++count;
            }
        }
        ans = min(count, ans);
        return ans;
    }
};