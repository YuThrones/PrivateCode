// 这道题看过，但是一时忘记了，查了一下，还是使用动态规划解决，需要注意的是切分的方式比较难确定，是从最小的区间往打拓展，每次遍历选定一个气球作为最后打爆的气球
// 然后求左右区间先打爆的最大收益，迭代顺序必须严格按照小区间到大

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > dp(len + 2);
        for (int i = 0; i < len + 2; ++i) {
            dp[i].resize(len + 2);
        }
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        for (int step = 0; step <= len; ++step) {
            // step从小到大，保证dp使用时较小的都已经算好
            for (int i = 1; i + step <= len; ++i) {
                // 根据step找到每一个需要计算的固定长度的区间，如果右边已经超过len不需要进行计算
                int left = i;
                int right = i + step;
                dp[left][right] = 0;
                for (int j = i; j <= i + step; ++j) {
                    // 寻找每个气球作为最后一个打爆的
                    // 找到左边[i, j-1]闭区间和右边[j+1, i+step]闭区间作为先打爆的最大值
                    int sum = nums[left - 1] * nums[j] * nums[right + 1];
                    int temp = 0;
                    
                    if (left <= j - 1) sum += dp[left][j - 1];
                    if (right >= j + 1) sum += dp[j + 1][right];
                    dp[left][right] = max(sum, dp[left][right]);
                }
            }    
        }
        return dp[1][len];
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<int> input{3,1,5,8};
    cout << s.maxCoins(input);
    return 0;
}