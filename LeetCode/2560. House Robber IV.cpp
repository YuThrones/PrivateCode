// 这道题因为需要计算的不是钱数，而是户数，所以可以用贪心来判断一个能力值是否可以打劫足够的户数
// 整体大思路则是用二分来做

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int ans = r;
        while(l <= r) {
            int m = l + ((r - l) >> 1);
            if (ok(nums, k, m)) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    bool ok(vector<int>& nums, int k, int ability) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= ability) {
                ++ans;
                ++i;
            }
        }
        return ans >= k;
    }
};

int main() {
    Solution sol;
    vector<int> nums{2,3,5,9};
    int k = 2;
    sol.minCapability(nums, k);
}