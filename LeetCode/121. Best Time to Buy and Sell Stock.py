# 单次遍历即可解决，保存到当前为止的借个最小值以及收益的最大值，两个值不断更新即可

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if (len(prices) == 0):
            return 0
        max_profit = 0
        min_price = None
        
        for price in prices:
            if (min_price is not None):
                profit = price - min_price
                if (profit > max_profit):
                    max_profit = profit
            if (min_price is None or price < min_price):
                min_price = price
        return max_profit
            