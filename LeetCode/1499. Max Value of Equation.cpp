// 这道题要用单调队列来做，事实上就是求满足xj - xi <= K的情况下，xj + yj + yi - xi
// 单调队列从大到小维持yi - xi的值

#include<vector>
#include<limits.h>
using namespace std;

#define MAIN_MAX  10

class Solution {
public:
    int dq[MAIN_MAX];
    int diff[MAIN_MAX];
    int h;
    int t;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        h = 0;
        t = -1;
        int xj, yj;
        for (int j = 0; j < points.size(); ++j) {
            xj = points[j][0];
            yj = points[j][1];
            
            // 距离超过k的出队列
            while(h <= t && xj - points[dq[h]][0] > k) {
                ++h;
            }

            // 结算下目前的答案
            if (h <= t) {
                ans = max(ans, xj + yj + points[dq[h]][1] - points[dq[h]][0]);
            }
            
            diff[j] = yj - xj;
            while(h <= t && diff[dq[t]] < diff[j]) {
                --t;
            }
            dq[++t] = j;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> points{{0, 0}, {3, 0}, {9, 2}};
    int k = 3;
    int ans = sol.findMaxValueOfEquation(points, k);
    return 0;
}