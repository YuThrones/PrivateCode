# 思路挺简单的，递归调用函数就可以搞定，优化一下转成循环即可
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if (n == 0):
            return 1
        remember = 1
        need_revert = False
        if (n < 0):
            need_revert = True
            n = -n
        while (n > 1):
            print (x, n, remember)
            if (n % 2 == 1):
                remember *= x
            x = x * x
            n  = n // 2
        result = remember * x
        if (need_revert):
            return 1 / result
        return result
