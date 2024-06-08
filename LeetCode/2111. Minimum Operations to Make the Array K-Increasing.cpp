// 这道题其实就是按k的间隔分组，转化成多个最长不下降子序列的问题

#include<vector>
#include<memory.h>
#include<algorithm>
#include<limits.h>
using namespace std;

#define MAX_N 100001

class Solution {
public:
    int nums[MAX_N];
    int dp[MAX_N];
    int size;
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            size = 0;
            for (int j = i; j < n; j += k) {
                nums[size++] = arr[j];
            }
            ans += size - getLongestNotDecreasingNum();
        }
        return ans;
    }

    int getLongestNotDecreasingNum() {
        int maxLen = 1;
        for (int i = 0; i < size; ++i) {
            dp[i] = INT_MAX;
        }
        dp[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            int index = upper_bound(dp, dp + maxLen, nums[i]) - dp;
            if (index == maxLen) {
                ++maxLen;
            }
            dp[index] = nums[i];
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> arr{4,1,5,2,6,2};
    // vector<int> arr{5, 4, 3, 2, 1};
    int k = 2;
    // int k = 1;
    sol.kIncreasing(arr, k);
}