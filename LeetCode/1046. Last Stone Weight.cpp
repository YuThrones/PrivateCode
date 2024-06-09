// 这题本质上分析完其实就是把石头分两组，让他们的和最小，这样相互碰撞抵消之后能剩下的最小
// 也就转化成一个01背包问题，求累加和sum一半的背包容量的最大价值

#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (auto& num: stones) {
            for (int i = target; i >= num; --i) {
                dp[i] = max(dp[i], dp[i - num] + num);
            }
        }

        return sum - dp[target] * 2;
    }
};
