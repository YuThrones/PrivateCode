// 这道题是可以用递归改动态规划做的，不过因为一眼看出来动态规划的写法，就直接写动态规划了

#include<vector>
#include<numeric>
#include<iostream>
using namespace std;


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int start = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

        int total = accumulate(nums.begin(), nums.end(), 0);
        
        for (int step = 0; step < nums.size(); ++step) {
            for (int i = 0; i + step < nums.size(); ++i) {
                if (step == 0) {
                    dp[i][i + step] = nums[i];
                    continue;
                }
                
                if (step == 1) {
                    dp[i][i + step] = max(nums[i], nums[i + step]);
                    continue;
                }
                
                if (dp[i + 1][i + step] < dp[i][i + step - 1]) {
                    dp[i][i + step] = nums[i] + min(dp[i + 1 + 1][i + step], dp[i + 1][i + step - 1]);
                }
                else {
                    dp[i][i + step] = nums[i + step] + min(dp[i + 1][i + step - 1], dp[i][i + step - 1 - 1]);
                }
            }    
        }
        return dp[0][nums.size() - 1] * 2 >= total;
    }
    
};

int main() {
    Solution solution;
    // vector<int> input{1,5,233,7};
    vector<int> input{1, 3, 1};
    cout << solution.PredictTheWinner(input) ;
    return 0;
}