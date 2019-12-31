# 这道题我的思路使用二分搜索，通过递归解决子问题来求解
# 每次找到中间点，然后把中间点前面和中间点后面的解的数量相乘，加到当前字符串的解的数目当中
# 这样就只剩下一种情况没有包括进去，那就是有一个两位数横跨了前后，判断这个两位数是否合法，如果合法，就直接把除了这个两位数之外前面和后面的解的数目相乘加上即可
# 需要注意这里有一种特殊情况，那就是二位数的前面或者后面已经没有多余的数字了，这种情况下视为前面或者后面有一组解
# 另外加上一个已有的结果记录来去除重复计算，可以稍微提高效率

# 看了下其他人的答案，发现自己想多了，其实动态规划就行，用一个n+1的数组储存字符串前x位的解的数目，然后n的解的数目可以通过n-1和n-2的值来求解，取决于s[n-1:n]和s[n-2:n]是否合法
# 另外写了一个DP的做法，试了下，确实要快50%，而且容易理解
class Solution:
    repeat = {}
    def numDecodings(self, s: str) -> int:
        if (s in self.repeat):
            return self.repeat[s]
        length = len(s)
        if (length == 0):
            return 0
        if (length == 1):
            if (int(s) > 0):
                self.repeat[s] = 1
                return 1
            else:
                self.repeat[s] = 0
                return 0
        mid = length // 2
        count = 0
        count += self.numDecodings(s[:mid]) * self.numDecodings(s[mid:])
        
        if ((len(s[mid-1:mid+1])) == 2):
            midnum = int(s[mid-1:mid+1])
            if (midnum >= 10 and midnum <= 26):
                leftcount = self.numDecodings(s[:mid-1])
                rightcount = self.numDecodings(s[mid+1:])
                if (len(s[:mid-1]) == 0):
                    leftcount = 1
                if (len(s[mid+1:]) == 0):
                    rightcount = 1
                count += leftcount * rightcount
        self.repeat[s] = count
        return count

class Solution:
    def numDecodings(self, s: str) -> int:
        length = len(s)
        result = [0]
        result[0] = 1 if (s[0] != '0') else 0
        for end in range(length):
            onestr = s[end]
            twostr = s[end-1:end+1]

            count = 0
            if (len(onestr) == 1):
                if (int(onestr) > 0 and int(onestr) < 10):
                    count += result[end]
            if (len(twostr) == 2):
                if (int(twostr) >= 10 and int(twostr) <= 26):
                    count += result[end-1]
            result.append(count)
        return result[-1]