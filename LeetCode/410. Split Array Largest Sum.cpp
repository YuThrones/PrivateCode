// 我的想法是利用递归改动态规划然后加缓存，虽然能过但是速度很慢
// 看了下最快解法，是利用类似二分的方式，压缩答案可能的空间然后尝试得到最优解
// 我的复杂度是O(mn),二分的方式应该是O(log(10的9次方)n)，应该要快一点

#include<vector>
#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> cumulate;
        cumulate.push_back(0);
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            temp += nums[i];
            cumulate.push_back(temp);
        }
        
        // // 某个index结尾分成n段的结果
        // vector<vector<int>> dp;
        // for (int i = 0; i < nums.size(); ++i) {
        //     dp.push_back(vector<int>(m, INT_MAX));
        // }
        
        vector<vector<int>> dp;
        for (int i = 0; i <= m; ++i) {
            dp.push_back(vector<int>(nums.size(), -1));
        }
        return yu(m, cumulate, nums.size() - 1, dp);
    }
    
    int yu(int m, vector<int>& cumulate, int end, vector<vector<int>>& dp) {
        if (dp[m][end] != -1) return dp[m][end];

        if (m == 1) {
            dp[m][end] = cumulate[end + 1] - cumulate[0];
            return dp[m][end];
        }
        
        if (end < m - 1) {
            dp[m][end] = INT_MAX;
            return dp[m][end];
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < end; ++i) {
            int sub_ans = yu(m - 1, cumulate, i, dp);
            if (sub_ans == -1) {
                continue;
            }
            int temp = cumulate[end + 1] - cumulate[i + 1];
            ans = min(max(temp, sub_ans), ans);
        }

        dp[m][end] = ans;
        return dp[m][end];
    }
};

int main() {
    Solution solution;
    vector<int> nums{7,2,5,10,8};
    int m = 2;
    cout << solution.splitArray(nums, m) << endl;
    return 0;
}