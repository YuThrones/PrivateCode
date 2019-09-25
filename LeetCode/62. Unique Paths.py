# 因为只有向下和向右两个方向，所以直接递归就可以解决问题 。看了下最快的答案，是用循环替代递归，而且用一个一维数组来存储复用，效率应该更高
class Solution:
    test = {}
    def uniquePaths(self, m: int, n: int) -> int:
        if ((m, n) in self.test):
            return self.test[(m, n)]
        if(m <= 1 or n <= 1):
            self.test[(m,n)] = 1
            return 1
        count = 0
        if (m > 1):
            count += self.uniquePaths(m-1, n)
        if (n > 1):
            count += self.uniquePaths(m, n-1)
        self.test[(m,n)] = count
        return count