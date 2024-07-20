// 这道题还是动态规划，关键点有两个，第一个是排序cuts不影响结果，要先排序
// 第二个是在cuts前后加上0和n，这样当在(l,r)范围上的i位置进行切割的时候，直接用r+1位置和l-1位置的值一减就可以得出切割代价

#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int sz = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<int> newCuts(sz + 2);
        newCuts[0] = 0;
        for (int i = 0; i < sz; ++i) {
            newCuts[i + 1] = cuts[i];
        }
        newCuts[sz + 1] = n;
        vector<vector<int>> dp(sz + 2, vector<int>(sz + 2, 0));
        
        for (int l = sz; l > 0; --l) {
            for (int r = l; r <= sz; ++r) {
                int temp = INT_MAX;
                for (int i = l; i <= r; ++i) {
                    temp = min(temp, dp[l][i - 1] + dp[i + 1][r]);
                }
                dp[l][r] = temp + newCuts[r + 1] - newCuts[l - 1];
            }
        }

        return dp[1][sz];
    }

    int cal(vector<vector<int>>& dp, vector<int>& cuts, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int ans = INT_MAX;
        if (l == r) {
            ans = cuts[r + 1] - cuts[l - 1];
        }
        else {
            for (int i = l; i <= r; ++i) {
                ans = min(ans, cal(dp, cuts, l, i - 1) + cal(dp, cuts, i + 1, r));
            }
            ans += cuts[r + 1] - cuts[l - 1];
        }
        dp[l][r] = ans;
        return ans;
    }
};

int main() {
    int n = 7;
    vector<int> cuts{1, 4, 3, 5};
    Solution sol;
    sol.minCost(7, cuts);
}