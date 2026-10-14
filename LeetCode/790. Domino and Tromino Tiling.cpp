// 自己用一个数组推导有点难，看了下ds，加一个一个辅助数组top
// top[i]表示填满了2 * (i - 1), 只是在 i 列上面或者下面留下了一个缺口，需要后面来填

class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<long long> dp(n + 1, 0), top(n + 1, 0);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        top[0] = 0; top[1] = 0; top[2] = 1;

        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2] + 2 * top[i-1]) % MOD;
            top[i] = (dp[i-2] + top[i-1]) % MOD;
        }
        return dp[n];
    }
};