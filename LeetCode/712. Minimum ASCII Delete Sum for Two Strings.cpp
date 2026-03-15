class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + s1[i];
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        int d1 = 0;
        int d2 = 0;
        for (int i = 0; i < n1; ++i) {
            d1 += s1[i];
        }
        for (int j = 0; j < n2; ++j) {
            d2 += s2[j];
        }
        return d1 + d2 - 2 * dp[n1][n2];
    }
};