// 这道题就是变形的背包，只是可能性变成了多个方案中的一个，记得做一个前缀数组统计硬币价值即可

#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;


class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int ans = 0;
        int dp[k + 1];
        memset(dp, 0, sizeof(dp));
        int value[k + 1];
        int n = piles.size();
        int size = 0;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            size = min(k, (int)piles[i].size());
            sum = 0;
            value[0] = 0;
            for (int j = 0; j < size; j++) {
                sum += piles[i][j];
                value[j + 1] = sum;
            }

            // 尝试同一个栈拿不同数量硬币的方案
            for (int j = k; j > 0; --j) {
                for (int k = 1; k <= size; ++k) {
                    if (j - k < 0) break;
                    dp[j] = max(dp[j], dp[j - k] + value[k]);
                }
            }
        }
        return dp[k];
    }
};

int main() {
    vector<vector<int>> piles{{37,88},{51,64,65,20,95,30,26},{9,62,20},{44}};
    int k = 9;

    Solution sol;
    sol.maxValueOfCoins(piles, k);
    return 0;
}