// 一开始想着有什么奇妙的数学方式，事实上直接递归转动态规划就完事了

#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 1) return 0;
        vector<int> dp;
        while (dp.size() < 2) {
            dp.push_back(1);
        }
        for (int i = 1; i <= n; ++i) {
            cal2(i, dp);
        }
        return dp[n];
    }
    
    int cal2(int n, vector<int>& dp) {
        if (n < dp.size()) {
            return dp[n];
        }
        int ans = 0;
        for (int i = 1; i < dp.size(); ++i) {
            ans = max(max(ans, (n - i) * dp[i]), (n - i) * i);
        }
        dp.push_back(ans);
        return ans;
    }
};

int main() {
    Solution sol;
    sol.integerBreak(10);
    return 0;
}