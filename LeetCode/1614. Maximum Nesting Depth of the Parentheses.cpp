class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int left = 0;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++left;
                ans = max(left, ans);
            }
            else if (s[i] == ')') {
                --left;
            }
        }
        return ans;
    }
};