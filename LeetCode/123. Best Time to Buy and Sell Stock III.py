# 这道题自己没有想出来，参考了https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution的答案自己写一遍
# 关键是要找到动态规划公式dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1],其中k代表一共进行k次交易，i代表到第i天为止
# 然后在这个公式的基础上进行优化

# 根据动态规划公式写的基础版本，在Leetcode上会超时
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        if (length == 0):
            return 0
        
        dp = []
        for i in range(3):
            dp.append([0] * length)
        
        for k in range(1, 3):
            for i in range(1, length):
                # 这里的min_value事实上等于(prices[j] - dp[k-1, j-1]),min_value越小，prices[i] - prices[j] + dp[k-1, j-1]越大
                min_value = prices[0]
                for j in range(1, i + 1):
                    min_value = min(min_value, prices[j] - dp[k - 1][j - 1])
                    
                dp[k][i] = max(dp[k][i - 1], prices[i] - min_value)
        return dp[2][length - 1]

# 优化一层内层循环，在Leetcode上勉强能过，但是速度很慢，只能超过11.56%，用时1464ms。
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        if (length == 0):
            return 0
        
        dp = []
        for i in range(3):
            dp.append([0] * length)
        
        for k in range(1, 3):
            min_value = prices[0]
            for i in range(1, length):
                这里进行了优化，在计算前面的值的时候直接算min_value，避免min_value重复计算
                min_value = min(min_value, prices[i] - dp[k - 1][i - 1])
                dp[k][i] = max(dp[k][i - 1], prices[i] - min_value)
        return dp[2][length - 1]

# 这一做法跟上一步复杂度完全一致，只是把内外循环对调，因此需要一个min_list来存储当前行prices[i] - dp[k - 1][i - 1]的最小值，为下一步的优化做准备
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        if (length == 0):
            return 0
        
        dp = []
        min_list = []
        for i in range(3):
            dp.append([0] * length)
            min_list.append(prices[0])
        
        for i in range(1, length):
            for k in range(1, 3):
                min_list[k] = min(min_list[k], prices[i] - dp[k - 1][i - 1])
                dp[k][i] = max(dp[k][i - 1], prices[i] - min_list[k])
        
        return dp[2][length - 1]


# 对调循环之后可以发现i的值只取决于i-1的值，因此可以压缩dp成为一个一维数组，节省空间
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        if (length == 0):
            return 0
        
        dp = []
        min_list = []
        for i in range(3):
            dp.append(0)
            min_list.append(prices[0])
        
        for i in range(1, length):
            for k in range(1, 3):
                # 这个地方dp[k-1][i-1]变成了dp[k-1]我是认为存疑的，因为这时候dp[k-1]事实上等于dp[k-1][i]，不过因为包含i事实上结果也是一样的，所以也没区别
                min_list[k] = min(min_list[k], prices[i] - dp[k - 1])
                dp[k] = max(dp[k], prices[i] - min_list[k])
        
        return dp[2]

# 这个是对这个题目做的特异性优化，因为确定k最大值为2，因此可以取消数组，直接使用变量名来存储
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy1, buy2 = 9999999, 9999999
        sell1, sell2 = 0, 0
        
        length = len(prices)
        for i in range(length):
            buy1 = min(buy1, prices[i])
            sell1 = max(sell1, prices[i] - buy1)
            buy2 = min(buy2, prices[i] - sell1)
            sell2 = max(sell2, prices[i] - buy2)
        
        return sell2