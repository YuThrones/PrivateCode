class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++cnt;
            }
            else if (s[i] == ')') {
                --cnt;
                if (cnt < 0) {
                    cnt = 0;
                    ++ans;
                }
            }
        }
        ans += cnt;
        return ans;
    }
};