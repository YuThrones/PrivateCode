// 这道题得用动态规划，一次性把酒水倒完，一杯一杯模拟太复杂了

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(100, 0);
        dp[0] = poured;
        for(int i = 1; i <= query_row; ++i) {
            for(int j = i; j >= 0; --j) {
                if(j > 0) {
                    dp[j] = getOver(dp[j - 1]) + getOver(dp[j]);
                }
                else {
                    dp[j] = getOver(dp[j]);
                }
            }
        }
        return min(dp[query_glass], 1.0);
    }

    double getOver(double last) {
        if (last > 1.0) {
            return (last - 1.0) / 2;
        }
        return 0.0;
    }
};