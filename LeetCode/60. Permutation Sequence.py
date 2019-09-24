# 这道题第一反应是递归调用生成序列，但是仔细想想，其实他不需要前面的那部分，他只需要生成一个字符串，所以可以根据这个字符串的次序，算出每一个位置使用的是第x小的数字
# 从前往后每一位都根据这个原则来算出使用的数字即可
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        use = {}
        fib = [1]
        total = 1
        for i in range(n):
            total *= (i+1)
            fib.append(total)
        result = []
        self.fib = {}
        k -= 1
        for i in range(n):
            divide = fib[n - i - 1]
            quotient = k // divide
            
            k = k % divide
            count = 0
            for i in range(1, n+1):
                if (i in use):
                    continue
                if (count >= quotient):
                    result.append(str(i))
                    use[i] = True
                    break
                else:
                    count += 1
        return "".join(result)
    