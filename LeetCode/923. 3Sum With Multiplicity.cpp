// 思路是不难的，首先是因为范围有限，所以只需要统计每个数字数量就行
// 其次，对两数相等，三数相等的情况进行额外处理，计算方式不同

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1'000'000'007;
        vector<long long> count(101, 0);

        for (int x : arr) {
            count[x]++;
        }

        auto C2 = [](long long x) -> long long {
            return x * (x - 1) / 2;
        };

        auto C3 = [](long long x) -> long long {
            return x * (x - 1) * (x - 2) / 6;
        };

        long long ans = 0;

        for (int i = 0; i <= 100; ++i) {
            if (count[i] == 0) continue;

            for (int j = i; j <= 100; ++j) {
                if (count[j] == 0) continue;

                int k = target - i - j;

                // 保证 i <= j <= k，并且 k 在合法范围内
                if (k < j || k > 100 || count[k] == 0) continue;

                long long cur = 0;

                if (i == j && j == k) {
                    // 三个数都相同
                    cur = C3(count[i]);
                } else if (i == j) {
                    // 前两个数相同
                    cur = C2(count[i]) * count[k];
                } else if (j == k) {
                    // 后两个数相同
                    cur = count[i] * C2(count[j]);
                } else {
                    // 三个数都不同
                    cur = count[i] * count[j] * count[k];
                }

                ans = (ans + cur % MOD) % MOD;
            }
        }

        return (int)ans;
    }
};