// 这道题空间压缩感觉不太好弄，动态规划差不多了

#define MAX_N 25
#define MAX_K 100

class Solution {
public:
    double dp[MAX_N][MAX_N][MAX_K + 1];
    double knightProbability(int n, int k, int row, int column) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l <= k; ++l) {
                    dp[i][j][l] = -1;
                }
            }
        }
        return compute(n, k, row, column);
    }

    double compute(int n, int k, int row, int column) {
        if (row < 0 || column < 0 || row >= n || column >= n) return 0;
        if (dp[row][column][k] != -1) return dp[row][column][k];


        double ans = 0;
        if (k == 0) {
            ans = 1;
        }
        else {
            ans += compute(n, k - 1, row - 1, column - 2) / 8;
            ans += compute(n, k - 1, row - 1, column + 2) / 8;
            ans += compute(n, k - 1, row + 1, column - 2) / 8;
            ans += compute(n, k - 1, row + 1, column + 2) / 8;
            ans += compute(n, k - 1, row - 2, column - 1) / 8;
            ans += compute(n, k - 1, row - 2, column + 1) / 8;
            ans += compute(n, k - 1, row + 2, column - 1) / 8;
            ans += compute(n, k - 1, row + 2, column + 1) / 8;
        }

        dp[row][column][k] = ans;
        return ans;
    }
};

int main() {
    Solution sol;
    sol.knightProbability(3, 2, 0, 0);
    return 0;
}