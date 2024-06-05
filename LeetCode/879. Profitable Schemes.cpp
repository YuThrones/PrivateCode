// 递归->三维动态规划->空间压缩

#include<vector>
#include<memory.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // dp[r][s] 表示用前r个人搞定s的利润有几种可能性
        int dp[n + 1][minProfit + 1];
        memset(dp, 0, sizeof(dp));
        for (int r = 0; r <= n; ++r) {
            // 空利润不需要搞定了，必然有一种可能
            dp[r][0] = 1;
        }

        int m = group.size();
        // 空间压缩，每一次循环表示依靠前i的项目的可能性
        for (int i = 0; i < m; ++i) {
            
            for (int r = n; r >= 0; --r) {
                for (int s = minProfit; s >= 0; --s) {
                    int p1 = dp[r][s]; // 这里其实拿到的是完成前i - 1个项目的数据，还没修改对，也就是放弃i这个项目的可能性
                    int p2 = group[i] <= r ? dp[r - group[i]][max(0, s - profit[i])] : 0 ;
                    dp[r][s] = (p1 + p2) % MOD; // 这里修改之后就是完成前i个项目拿到利润s的可能性了
                }
            }
        }

        return dp[n][minProfit];
    }
};