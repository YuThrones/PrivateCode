#include <vector>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0; // 无移动次数直接返回0
        const int MOD = 1e9 + 7;
        // 方向数组：上、下、左、右
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp[startRow][startColumn] = 1; // 初始位置
        int result = 0;

        for (int move = 1; move <= maxMove; move++) {
            vector<vector<long>> newDp(m, vector<long>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] == 0) continue; // 跳过无效状态
                    // 遍历四个方向
                    for (auto& dir : dirs) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        // 下一步移出边界：累加到结果
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                            result = (result + dp[i][j]) % MOD;
                        } 
                        // 下一步仍在网格内：更新新状态
                        else {
                            newDp[ni][nj] = (newDp[ni][nj] + dp[i][j]) % MOD;
                        }
                    }
                }
            }
            dp = newDp; // 更新dp为下一步状态
        }
        return result;
    }
};

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int k = 1000000000 + 7;
        int result = 0;
        vector<vector<vector<int>>> record;
        for (int i = 0; i <= maxMove; ++i) {
            record.push_back(vector<vector<int>> (m, vector<int>(n, -1)));
        }
        for (int i = 1; i <= maxMove; ++i) {
            result = (result + cal(m, n, i, startRow, startColumn, record)) % k;
        }
        return result;
    }

    int cal(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& record) {
        int k = 1000000000 + 7;
        int result = 0;
        if (maxMove == 0) {
            return 0;
        }
        if (record[maxMove][startRow][startColumn] != -1) {
            cout << "short " << maxMove << " " << startRow << " " << startColumn << " " << record[maxMove][startRow][startColumn] << endl;
            return record[maxMove][startRow][startColumn];
        }
        if (maxMove == 1) {
            if (startRow == 0) {
                ++result;
            }
            if (startRow == m - 1) {
                ++result;
            }
            if (startColumn == 0) {
                ++result;
            }
            if (startColumn == n - 1) {
                ++result;
            }
            record[maxMove][startRow][startColumn] = result;
            return result;
        }        
        if (startRow > 0) {
            result = (result + cal(m, n, maxMove - 1, startRow - 1, startColumn, record)) % k;
        }
        if (startRow < m - 1) {
            result = (result + cal(m, n, maxMove - 1, startRow + 1, startColumn, record)) % k;
        }
        if (startColumn > 0) {
            result = (result + cal(m, n, maxMove - 1, startRow, startColumn - 1, record)) % k;
        }
        if (startColumn < n - 1) {
            result = (result + cal(m, n, maxMove - 1, startRow, startColumn + 1, record)) % k;
        }
        record[maxMove][startRow][startColumn] = result;
        return result;
    }
};