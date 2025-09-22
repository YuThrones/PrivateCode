class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        char last = s[0];
        int count = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == last) {
                ++count;
            }
            else {
                ans = max(ans, count);
                count = 1;
                last = s[i];
            }
        }
        ans = max(ans, count);
        return ans;
    }
};