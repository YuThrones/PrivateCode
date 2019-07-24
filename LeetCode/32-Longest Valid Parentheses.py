# 这道题核心的思想是动态规划，用一个数组dp存储以这个索引为结尾的合法字符串的长度，默认为0
# 从前往后遍历，对每一个 ")"查找匹配的 "("，要么前一位就是"("，要么去掉前一位的dp数组对应的长度后前一位是"("，不满足说明找不到匹配
# 这样在遍历一次s之后就可以算出最长答案
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = []
        length = len(s)
        for _ in range(length):
            dp.append(0)
        result = 0
        for i in range(length):
            if (s[i] == "("):
                continue
            if (i - 1 < 0):
                continue
                
            if (s[i-1] == "("):
                dp[i] = 2
                if (i - 2 >= 0):
                    dp[i] += dp[i - 2]
            else:
                left_i = i - dp[i-1] -1
                if (left_i < 0):
                    continue
                if (s[left_i] == "("):
                    dp[i] = dp[i-1] + 2
                    if (left_i - 1 >= 0):
                        dp[i] += dp[left_i - 1]
            if (dp[i] > result):
                result = dp[i]
                    
                

        return result