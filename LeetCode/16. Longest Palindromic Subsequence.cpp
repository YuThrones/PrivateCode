class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));

        for(int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + i >= n) {
                    break;
                }
                if(i == 1) {
                    if (s[j] == s[j + i]) {
                        dp[j][j + i] = 2;
                    }
                }
                else {
                    if (s[j] == s[j + i]) {
                        dp[j][j + i] = max(dp[j][j + i], dp[j + 1][j + i - 1] + 2);
                    }
                    else {
                        dp[j][j + i] = max(dp[j + 1][j + i], dp[j][j + i - 1]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};