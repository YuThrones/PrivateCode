// 这道题得先用动态规划，然后优化空间为两个变量，自己没想到思路

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0];
        int cash = 0;
        for(int i = 1; i < prices.size(); ++i) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};