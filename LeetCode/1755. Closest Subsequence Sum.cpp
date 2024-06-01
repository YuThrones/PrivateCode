// 这道题需要用到双向BFS以及双指针，算是比较锻炼coding，边界需要很小心
// 核心思路是，把最长40位的数组分为左右两部分，把2 ^ 40的穷举拆成两个2个2 ^ 20的穷举
// 然后用双指针滑动贪心的方式，避免排列组合，更快求出答案
// 这道题有很多细节要注意：
// 1. 分两组之前整体排序，这样相同数字可以一次性处理，而不需要每一个都派生出两种可能，这样可以减掉很多重复可能性
// 2. 分组获得两个组所有可能的和之后需要分别进行第二次排序，以满足双指针贪心的需要
// 3. 把正数和负数的和分别加起来跟goal对比，如果goal大于正数之和或者小于负数之和，那么这个和就是答案，可以减掉一些时间

#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

#define MAIN_MAX 20

class Solution {
public:
    int lsum[1 << MAIN_MAX];
    int rsum[1 << MAIN_MAX];
    int fill;


    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        int minSum = 0, maxSum = 0;
        for (auto& i: nums) {
            if (i > 0) maxSum += i;
            else minSum += i;
        }
        if (maxSum < goal) return goal - maxSum;
        if (goal < minSum) return minSum - goal;

        sort(nums.begin(), nums.end());
        fill = 0;
        int lsize = compute(nums, 0, n / 2, 0, lsum);
        fill = 0;
        int rsize = compute(nums, n / 2, n, 0, rsum);

        sort(lsum, lsum + lsize);
        sort(rsum, rsum + rsize);

        // 双指针寻找答案
        int l = 0, r = rsize - 1;
        int ans = abs(lsum[l] + rsum[r] - goal);
        
        for(; l < lsize; ++l) {
            while (r > 0 && abs(lsum[l] + rsum[r - 1] - goal) <= abs(lsum[l] + rsum[r] - goal)) {
                --r;
            }
            ans = min(ans, abs(lsum[l] + rsum[r] - goal));
        }
        return ans;
    }

    int compute(vector<int>& nums, int i, int end, int s, int sum[]) {
        if (i == end) {
            sum[fill++] = s;
        }
        else {
            int j = i;
            while(j < end && nums[i] == nums[j]) ++j;

            // 相同数字统一处理
            for (int k = 0; k <= j - i; ++k) {
                compute(nums, j, end, s + k * nums[i], sum);
            }
        }
        return fill;
    }
};

int main() {
    Solution sol;
    vector<int> nums{1, 2, 3};
    int goal = -7;
    int ans = sol.minAbsDifference(nums, goal);
    return 0;
}