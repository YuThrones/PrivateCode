// 一开始想先写递归，但是没有理清楚对应关系，最开始用开头枚举，事实上应该用结尾枚举，看了discuss的方法，按照尾部枚举拿到一个位置结尾固定间隔一共有多少种可能性
// 第二个优化主要是改变了dp的含义，定义dp[i][j]为以i位置结尾，上一个位置为j的答案，复杂度一致，但是可以直接用数组可能会比哈希表跑起来快一点

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // 计算某个位置结尾的所有可能间隔的组合数量
        vector<unordered_map<long, int>> dp(nums.size());
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int cnt = 0;
                long interval = long(nums[i]) - long(nums[j]);
                if (interval < INT_MIN || interval > INT_MAX) continue;

                if (dp[j].find(interval) != dp[j].end()) {
                    cnt = dp[j][interval];
                }

                // 这里+1，是因为除了前面的都要的可能性，还有前面的可能性放弃他的开头的可能性，有点难理解
                dp[i][interval] = dp[i][interval] + cnt + 1;
                // 第一次发现间隔cnt是0，第二次是1，这时候刚好三个数，也就是说只有三个数的时候才会正常加上
                // cout << j << " " << i << " " << cnt << " " << interval << " " << dp[i][interval] << endl;

                res += cnt;
            }
        }
        return res;
    }


    int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
        unordered_map<int, vector<int>> a_idx;
        vector<vector<int>> dp(A.size(), vector<int>(A.size()));
        for (auto i = 0; i < A.size(); ++i)
            a_idx[A[i]].push_back(i);
        for (auto i = 0; i < A.size(); ++i)
            for (int j = 0; j < i; j++) {
                auto prev = 2l * A[j] - A[i];
                if (prev < INT_MIN || prev > INT_MAX)
                    continue;
                auto it = a_idx.find(prev);
                if (it != end(a_idx)) {
                    for (auto k : it->second) {
                        if (k >= j)
                            break;
                        dp[i][j] += dp[j][k] + 1;
                    }
                }
                res += dp[i][j];
            }
        return res;
    }
};