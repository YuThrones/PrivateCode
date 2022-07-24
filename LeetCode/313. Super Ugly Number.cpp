// 通过已有的ugly number，每个素数都有一个对应的ugly number下标表示当前这个素数用到哪一个来计算答案
// 看了下最快答案，更快的原因有两个，一个是用了数组来代替vector，第二个是用long long int规避了INT_MAX溢出的问题，其他没有区别

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 1), idx(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                if (INT_MAX / primes[j] >= dp[idx[j]]) {
                    dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
                }
            }
            for (int j = 0; j < primes.size(); ++j) {
                if ((INT_MAX / primes[j] >= dp[idx[j]]) && (dp[i] == dp[idx[j]] * primes[j])) {
                    ++idx[j];
                }
            }
        }
        return dp.back();
    }
};