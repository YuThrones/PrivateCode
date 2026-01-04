class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int l = 0;
        int r = 0;
        for (auto c : s) {
            if (c == 'L') {
                ++l;
            }
            else {
                ++r;
            }
            if (l == r) {
                ++ans;
                l = 0;
                r = 0;
            }
        }
        return ans;
    }
};