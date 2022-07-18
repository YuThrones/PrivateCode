// 这道题看过，但是一时忘记了，查了一下，还是使用动态规划解决，需要注意的是切分的方式比较难确定，是从最小的区间往打拓展，每次遍历选定一个气球作为最后打爆的气球
// 然后求左右区间先打爆的最大收益，迭代顺序必须严格按照小区间到大
// 看了下最快答案，思路是一样的，但是存储他使用了一维数组来代替二维vector，速度是要强不少，把自己的代码全改一维数组，速度确实提升了很多

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        int M = len + 2;
        int * dp = new int [M * M];
        
        int* input = new int[nums.size() + 2];
        input[0] = 1;
        memcpy(input + 1, nums.data(), nums.size() * sizeof(int));
        input[nums.size() + 1] = 1;
        // nums.insert(nums.begin(), 1);
        // nums.push_back(1);
        
        for (int step = 0; step <= len; ++step) {
            // step从小到大，保证dp使用时较小的都已经算好
            for (int i = 1; i + step <= len; ++i) {
                // 根据step找到每一个需要计算的固定长度的区间，如果右边已经超过len不需要进行计算
                int left = i;
                int right = i + step;
                dp[left * M + right] = 0;
                for (int j = i; j <= i + step; ++j) {
                    // 寻找每个气球作为最后一个打爆的
                    // 找到左边[i, j-1]闭区间和右边[j+1, i+step]闭区间作为先打爆的最大值
                    int sum = input[left - 1] * input[j] * input[right + 1];
                    int temp = 0;
                    
                    if (left <= j - 1) sum += dp[left * M + j - 1];
                    if (right >= j + 1) sum += dp[(j + 1) * M + right];
                    dp[left * M + right] = max(sum, dp[left * M +right]);
                }
            }    
        }
        return dp[1 * M + len];
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<int> input{3,1,5,8};
    cout << s.maxCoins(input);
    return 0;
}