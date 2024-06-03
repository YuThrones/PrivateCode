// 暴力递归改动态规划，注意边界条件就行

#include<vector>
#include<limits.h>
using namespace std;

#define MAX_D 366

class Solution {
public:
    int dp[MAX_D];
    int durations[3]{1, 7, 30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        for (int i = 0; i < n; ++i) {
            dp[i] = INT_MAX;
        }
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 0, j = i; k < costs.size(); ++k) {
                while(j < n && days[i] + durations[k] > days[j]) {
                    ++j;
                }
                dp[i] = min(dp[i], dp[j] + costs[k]);
            }
        }
        return dp[0];
    }
};