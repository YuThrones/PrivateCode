// 经典递归转动态规划，但是这道题远远不是最优解，最优解是算出0和1分别的数量，还有总的加起来的数量排序，然后从小到大尝试能满足的最多的个数，三个求出来的最小值就是答案
// 本质上是一种贪心，但是好像不好证明

class Solution {
public:
    static int solve(vector<int>& f, int m){
        int count = 0;
        for (auto i : f) {
            if (i > m)
                break;
            m -= i;
            ++count;
        }
        return count;
    }
    
    static int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<int> zero(l), one(l), both(l);
        for (int i = 0; i < l; ++i) {
            int zeros = count(strs[i].begin(), strs[i].end(), '0');
            zero[i] = zeros;
            one[i] = strs[i].size() - zeros;
            both[i] = strs[i].size();
        }
        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        sort(both.begin(), both.end());
        return min({solve(zero, m), solve(one, n), solve(both, m + n)});
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> one(strs.size());
        vector<int> zero(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            int countOne = 0;
            int countZero = 0;
            for (auto c: strs[i]) {
                if (c == '1') ++countOne;
                else ++countZero;
            }
            one[i] = countOne;
            zero[i] = countZero;
        }
        vector<unordered_map<int, unordered_map<int, int>>> dp(strs.size() + 1);
        return yu(one, zero, m, n, 0, dp);
    }
    
    int yu(vector<int>& one, vector<int>& zero, int m, int n, int start, vector<unordered_map<int, unordered_map<int, int>>>& dp) {
        if (start >= one.size()) return 0;
        if (m <= 0 && n <= 0) return 0;
        
        if (dp[start].find(m) != dp[start].end() && dp[start][m].find(n) != dp[start][m].end()) {
            return dp[start][m][n];
        }
        
        int count = 0;
        if (one[start] <= n && zero[start] <= m) {
            count = max(count, yu(one, zero, m - zero[start], n - one[start], start + 1, dp) + 1);
        }
        count = max(count, yu(one, zero, m, n, start + 1, dp));
        
        dp[start][m][n] = count;
        return count;
    }
};
// 经过递归改动态规划，剪枝，空间压缩后的最优版本
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (auto& s: strs) {
            int zeros = 0;
            int ones = 0;
            for (auto& c: s) {
                if (c == '1') ones++;
                else zeros++;
            }

            for (int z = m; z >= zeros; --z) {
                for (int o = n; o >= ones; --o) {
                    dp[z][o] = max(dp[z][o], 1 + dp[z - zeros][o - ones]);
                }
            }
        }
        return dp[m][n];
    }
};