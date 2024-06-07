// 这道题总体思路是先把每个位置开头的k长度的串的累加和算出来，
// 然后利用这个算出一个位置之前的k长度的最大累加和的开头，
// 和一个位置之后k长度的最大累加和的开头，
// 然后利用这三个辅助数据，用一个k长度的串把数组分成三部分，分别算出最大值，
// 枚举所有分割可能得出最后答案，要注意的是边界容易写错

#include<vector>
#include<memory.h>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum[n];
        int prefix[n];
        int suffix[n];
        memset(sum, 0, sizeof(sum));
        memset(prefix, 0, sizeof(sum));
        memset(suffix, 0, sizeof(suffix));

        int l = 0, r = 0;
        int temp = 0;
        for (; r < n; ++r) {
            temp += nums[r];
            if (r - l + 1 == k) {
                sum[l] = temp;
                temp -= nums[l];
                ++l;
            }
        }

        prefix[k - 1] = 0;
        for (int i = k; i < n; ++i) {
            if (sum[i - k + 1] > sum[prefix[i - 1]]) {
                prefix[i] = i - k + 1;
            }
            else {
                prefix[i] = prefix[i - 1];
            }
        }

        suffix[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            if (sum[i] >= sum[suffix[i + 1]]) {
                suffix[i] = i;
            }
            else {
                suffix[i] = suffix[i + 1];
            }
        }

        int a, b, c;
        int maxSum = 0;
        for (int i = k; i <= n - k * 2; ++i) {
            // 中间取一段k长度的，前后各留k长度，找到最大的开始索引
            temp = sum[prefix[i - 1]] + sum[i] + sum[suffix[i + k]];
            if (temp > maxSum) {
                maxSum = temp;
                a = prefix[i - 1];
                b = i;
                c = suffix[i + k];
            }
        }

        return {a, b, c};
    }
};

int main() {
    Solution sol;
    vector<int> nums{7,13,20,19,19,2,10,1,1,19};
    int k = 3;
    sol.maxSumOfThreeSubarrays(nums, k);
    return 0;
}