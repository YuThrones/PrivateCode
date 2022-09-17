// 自己是写了带记忆的递归，最快答案感觉有点取巧，只考虑除以2到7整除的

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<vector<int>> dp(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            handle(nums, i, dp);
        }
        for (auto sub: dp) {
            if (sub.size() > res.size()) {
                res = sub;
            }
        }
        return res;
    }
    
    // 一定要使用当前位置的话，尽量选更多
    vector<int> handle(vector<int>& nums, int start, vector<vector<int>>& dp) {
        vector<int> res;
        if (start == nums.size()) {
            return res;
        }
        if (!dp[start].empty()) {
            return dp[start];
        }
        
        vector<int> maxSub = dp[nums.size()];
        for (int j = nums.size() - 1; j > start; --j) {
            if (nums[j] % nums[start] == 0) {
                vector<int> sub = handle(nums, j, dp);
                maxSub = sub.size() > maxSub.size() ? sub : maxSub;
            }
        }
        
        res.push_back(nums[start]);
        for (auto n: maxSub) {
            res.push_back(n);
        }
        
        dp[start] = res;
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> input {3, 4, 8, 16};
    sol.largestDivisibleSubset(input);
}