// 核心思路是用dp存储到达dp的概率，到了N之后再把大于等于K，小于N的累积起来作为答案
// 计算dp的方式就是他有平均的概率从前面maxPts个数来

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k > n) {
            return 0;
        }
        vector<double> dp(n + 1, 0);
        dp[0] = 1;
        double windows = 0;
        for(int i = 1; i <= n; ++i) {
            if (i <= k) {
                windows += dp[i - 1];
            }
            if (i - maxPts - 1 >= 0 && i - maxPts - 1 < k) {
                windows -= dp[i - maxPts - 1];
            }
            // 因为每次抽卡都是1 - maxPts的范围，所以每个转移过来的概率都是 1/ maxPts，这里除法其实是每个单独除以概率
            dp[i] = windows / maxPts;
        }
        double ans = 0;
        for(int i = k; i <= n; ++i) {
            ans += dp[i];
        }
        return ans;
    }
};