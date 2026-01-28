class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> last(26, -1);
        int ans = -1;
        for(int i = 0; i < s.length(); ++i) {
            char c = s[i];
            int li = last[c - 'a'];
            if (li >= 0) {
                ans = max(ans, i - li - 1);
            }
            else {
                last[c - 'a'] = i;
            }
        }
        return ans;
    }
};