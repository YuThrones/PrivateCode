// 递归->三维动态规划

#include<vector>
#include<iostream>
using namespace std;

#define MOD 1000000007

class Solution {
public:

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // i,j位置路径和mod k 余数为r的个数
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 1; i < m; ++i) {
            for (int r = 0; r < k; ++r) {
                dp[i][0][r] = dp[i - 1][0][(r + k - grid[i][0] % k) % k] % MOD;
            }
        }

        for (int j = 1; j < n; ++j) {
            for (int r = 0; r < k; ++r) {
                dp[0][j][r] = dp[0][j - 1][(r + k - grid[0][j] % k) % k] % MOD;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int r = 0; r < k; ++r) {
                    dp[i][j][r] = dp[i - 1][j][(r + k - grid[i][j] % k) % k] % MOD;
                    dp[i][j][r] += dp[i][j - 1][(r + k - grid[i][j] % k) % k] % MOD;
                    dp[i][j][r] %= MOD;
                }
            }
        }

        // dp[i][j][l] = dp[i][j][l + grid[i][j]] grid[i][j]
        // dp[0][0][0] -> dp[1][0][0 + grid[1][0]]
        // dp[1][0][0] = dp[1][0][0]

        return dp[m - 1][n - 1][0];
    }

};

int main() {
    Solution sol;
    vector<vector<int>> grid{{7,3,4,9},{2,3,6,2},{2,3,7,0}};
    int k = 1;
    sol.numberOfPaths(grid, k);
    return 0;
}