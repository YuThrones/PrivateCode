这道题是典型的组合题，解题的方法好像是在编程珠玑看过，网上搜了一下，https://www.cnblogs.com/descusr/archive/2013/06/05/3118589.html
参考链接中的编程自己改成不受k影响的写法，事实上这个稍微改造一下就可以适用于所有的排列
比起使用递归，虽然看起来没有那么直观，但是避免了重复搜索的情况，效率会高很多
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if (k == 0):
            return []
        result = []
        index = []
        for i in range(k):
            index.append(i + 1)
        result.append(index[:])
        
        while (index[0] < n - k + 1):
            location = -1
            for ii, i in enumerate(index):
                if (ii + 1 >= k or i + 1 != index[ii + 1]):
                    location = ii
                    break
            index[location] += 1
            for pre in range(location):
                 index[pre] = pre + 1
            result.append(index[:])
        return result