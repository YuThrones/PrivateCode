// 经典递归改动态规划，先写出最简单的递归版本，然后根据矩阵关系改动态规划
// 看了下最快答案，也是递归改动态规划，但是好稍微快一点，没太看懂这个的实现思路，但是看起来时间复杂度应该是一致的，不知道为什么会稍微快一点

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> store(prices.size(), 0);
        int minSub = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            store[i] = max(prices[i] - minSub, store[i - 1]);
            int temp = prices[i];
            if (i - 2 >= 0) temp -= store[i - 2];
            minSub = min(minSub, temp);
        }
        return store[prices.size() - 1];
    }

    // int maxProfit(vector<int>& prices) {
    //     vector<int> store(prices.size(), -1);
    //     return cal(prices, prices.size() - 1, store);
    // }

    // int cal(vector<int>& prices, int end, vector<int>& store) {
    //     if (store[end] != -1) return store[end];
    //     if (end < 1) return 0;
    //     int res = cal(prices, end - 1, store);
    //     for (int i = end - 1; i >= 0; --i) {
    //         int temp = 0;
    //         if (prices[end] > prices[i]) {
    //             temp += prices[end] - prices[i];
    //         }
    //         if (i - 2 >= 0) {
    //             temp += cal(prices, i - 2, store);
    //         }
    //         res = max(res, temp);
    //     }
    //     store[end] = res;
    //     return res;
    // }
};


class Solution {
public:
    int f(int ind, int buy, vector<int>& prices,vector<vector<int>>&dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1,0,prices,dp), 0 + f(ind+1,1,prices,dp));
        }else{
            profit = max(prices[ind] + f(ind+2,1,prices,dp), 0 + f(ind+1,0,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        int n = prices.size();
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy <=1;buy++){
            int profit = 0;
            if(buy){
               profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }else{
               profit = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
          }
        }
        return dp[0][1];
    }
};

// prices
// store

// for prices[end] - prices[i] + store[i - 2]

// store[i - 2] - prices[i]

int main() {
    Solution s;
    // vector<int> input{1,2,3,0,2};
    vector<int> input{1, 4, 2};
    cout << s.maxProfit(input);
}