// 递归转动态规划，很经典的改写，还能再空间压缩下

#include<string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int l = 0; l < n - 1; ++l) {
            dp[l][l + 1] = s[l] == s[l + 1] ? 0 : 1;
        }

        for (int l = n - 3; l >= 0; --l) {
            for (int r = l + 2; r < n; ++r) {
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l + 1][r - 1];
                }
                else {
                    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }
};