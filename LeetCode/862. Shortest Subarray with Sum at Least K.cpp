#include <vector>
#include <limits.h>
using namespace std;

#define MAIN_MAX 100001

class Solution {
public:
    int dq[MAIN_MAX];
    long sums[MAIN_MAX];
    int h;
    int t;

    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        long total = 0;
        h = t = 0;
        sums[0] = 0;
        dq[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            sums[i + 1] = total;

            while(h <= t && total < sums[dq[t]]) {
                --t;
            }

            while(h <= t && total - sums[dq[h]] >= k) {
                ans = min(ans, i + 1 - dq[h]);
                ++h;
            }
            dq[++t] = i + 1;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums{84,-37,32,40,95};
    int k = 167;
    int ans = sol.shortestSubarray(nums, k);
    return 0;
}