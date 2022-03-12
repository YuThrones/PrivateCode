// 这个思路也很简单，每次一个价格比前面高就加起来就行
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) {
            return 0;
        }
        int res = 0;
        // int left = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};