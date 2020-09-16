# 同样单次遍历可以解决，只要后一天价格比前一天高，就认为可以前一天卖后一天卖，多天的买卖等价于这段时间每一天的和

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for index, price in enumerate(prices):
            if (index == 0):
                continue
            
            profit = price - prices[index - 1]
            if (profit > 0):
                max_profit += profit
            
        
        return max_profit