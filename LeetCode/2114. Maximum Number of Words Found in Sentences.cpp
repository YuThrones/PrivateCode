class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(string& s : sentences) {
            int n = 1;
            for(int i = 0; i < s.length(); ++i) {
                if (s[i] == ' ') {
                    ++n;
                }
            }
            ans = max(n, ans);
        }
        return ans;
    }
};