// 这道题关键就是想明白怎么画三角形，其实就是找一个中间点分成两边递归，然后改递推

#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        // if (values.size() < 3) return 0;
        // vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        // return f1(values, 0, values.size() - 1, dp);
        return f2(values);
    }

    int f1(vector<int>& values, int l, int r, vector<vector<int>>& dp) {
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int ans = INT_MAX;
        if (l == r - 2) {
            ans = values[l] * values[l + 1] * values[l + 2];
        }
        else {
            for (int i = l + 1; i < r; ++i) {
                ans = min(ans, values[l] * values[i] * values[r] + f1(values, l, i, dp) + f1(values, i, r, dp));
            }
        }
        if (ans == INT_MAX) ans = 0;
        dp[l][r] = ans;
        return ans;
    }

    int f2(vector<int> & values) {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), 0));
        int n = values.size();
        for (int l = n - 2; l >= 0; --l) {
            for (int r = l + 2; r < n; ++r) {
                int temp = INT_MAX;
                for (int i = l + 1; i < r; ++i) {
                    temp = min(temp, values[l] * values[i] * values[r] + dp[l][i] + dp[i][r]);
                }
                dp[l][r] = temp;
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    vector<int> values{1, 3, 1, 4, 1, 5};
    Solution sol;
    int ans = sol.minScoreTriangulation(values);
    return 0;
}

