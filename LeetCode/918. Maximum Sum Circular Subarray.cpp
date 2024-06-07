// 这道题很巧妙，相比普通的累加和问题，作出的唯一改进是多一个最小累加和的记录
// 这样环形数组最大累加和要么是不跨越头尾，也就是作为普通数组的最大累加和
// 要么跨越头尾，把中间连续的最小累加和减去，思路很值得学习

#include<vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int all = nums[0];
        int maxSum = nums[0];
        int maxPre = nums[0];
        int minSum = nums[0];
        int minPre = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            all += nums[i];

            maxPre = max(nums[i], maxPre + nums[i]);
            maxSum = max(maxSum, maxPre);
            
            minPre = min(nums[i], minPre + nums[i]);
            minSum = min(minSum, minPre);
        }

        return all == minSum ? maxSum : max(maxSum, all - minSum);
    }
};