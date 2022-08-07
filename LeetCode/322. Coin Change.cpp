// 这道题挺简单的，最基础的动态规划，不过比最快答案慢，看了下最快答案，是通过确定一个硬币范围，然后枚举检查是否能够凑出给定金币，跑起来确实更快，但是感觉有可能在最好和最坏差距很大的情况下反而会更慢，不能确定

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
		int temp;
        for (int i = 1; i <= amount; ++i) {
            for (int j = size - 1; j >= 0; --j) {
                if (coins[j] > i) continue;       
                if (dp[i - coins[j]] != -1) {
                    temp = dp[i - coins[j]] + 1;
                    if (dp[i] == -1 || dp[i] > temp) {
                        dp[i] = temp;
                    }
                }
            }
        }
        return dp[amount];
    }
    
};

int main() {
	Solution sol;
	vector<int> coins{1,2,5};
	int amount = 11;
	sol.coinChange(coins, amount);
	return 0;
}