// 每次选自己分割后加两边子区间的较大代价中，取最小的作递归
// 更快的答案有打表，也有多次计算共享计算过程的，思路一样

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp;
        for (int i = 0; i <= n; ++i) {
            vector<int> temp(n + 1, -1);
            dp.push_back(temp);
        }
        int res = cal(1, n, dp);
        return res;
    }
    
    int cal(int start, int end, vector<vector<int>>& dp) {
        if (start == end) {
            return 0;
        }

        if (start == end - 1) {
            return min(start, end);
        }
        
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        
        int res = INT_MAX;
        for (int i = start + 1; i < end; ++i) {
            int sub1 = cal(start, i - 1, dp);
            int sub2 = cal(i + 1, end, dp);
            res = min(res, max(sub1, sub2) + i);
        }
        dp[start][end] = res;
        
        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i < 100; ++i) {
        cout << sol.getMoneyAmount(i) << endl;
    }
    return 0;
}