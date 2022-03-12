// 记录前面最小一个数，然后遍历时更新这个最小值，并且判断是否能获得更大利润即可
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int minStart = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res = max(res, prices[i] - minStart);
            minStart = min(minStart, prices[i]);
        }
        return res;
    }
};