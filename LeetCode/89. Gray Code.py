# 子问题递归求解，每次把已有的列表按照倒序依次加上最前面的二进制代表的数字，然后插入列表中
# 因为子问题已经是连续的，按照反序加一位也是连续的，因此这样就可以保证连续性
# 每个子问题调用一次次方，这里是可以优化的，改成子问题放回自己的次方，乘以2就好了，不过影响不大
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if (n == 0):
            return [0]
        sub = self.grayCode(n - 1)
        length = len(sub)
        ext = pow(2,n-1)
        for index in range(length - 1, -1, -1):
            sub.append(ext+sub[index])
        return sub