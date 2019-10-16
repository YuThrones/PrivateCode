# 本质上就是求斐波那契数列，递归递推都行
class Solution:
    record = {}
    def climbStairs(self, n: int) -> int:
        if (n == 0 or n == 1):
            return 1
        if (n in self.record):
            return self.record[n]
        subsum = self.climbStairs(n - 1) + self.climbStairs(n - 2)
        self.record[n] = subsum
        return subsum