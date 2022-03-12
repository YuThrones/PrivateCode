// 这道题自己没有做出来，看了下别人解法，核心思路是通过第二次的最小价格，需要减去当前位置第一次的利润，这样子，之后的价格减去当前位置最小价格，就是把第一次的利润也加上了
// 感觉是暴力递归改出来的动态规划


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice1 = INT_MAX;
        int minPrice2 = INT_MAX;
        int profit1 = 0;
        int profit2 = 0;
        for (int i = 0; i < prices.size(); ++i) {
            minPrice1 = min(minPrice1, prices[i]);
            profit1 = max(profit1, prices[i] - minPrice1);
            minPrice2 = min(minPrice2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - minPrice2);
        }
        return profit2;
    }
};
