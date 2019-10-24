# 主要思路就是维持一个移动窗口，如果这个窗口不满足条件，就右边界扩张，如果满足条件，就尝试左边界收缩，直到不满足，继续扩张，反复执行这两步就可以
# 看了下leetcode的solution，做了一点优化，先对s遍历一边，把在t中的字符的索引记录下来，这样在维持窗口的时候就可以省去无关字符的部分，速度会更快
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        slen = len(s)
        tlen = len(t)
        start = -1
        end = -1
        request = {}
        for sub in t:
            if (not sub in request):
                request[sub] = 0
            request[sub] += 1
        record = {}
        count = 0
        for index, sub in enumerate(s):
            if (not sub in t):
                continue
            # print (request, record)
            if (not sub in record):
                record[sub] = []
            record[sub].append(index)
            count += 1
            if (len(record[sub]) > request[sub]):
                record[sub].pop(0)
                count -= 1
                
            if (count == tlen):
                minindex = -1
                for slist in record.values():
                    if (minindex == -1 or slist[0] < minindex):
                        minindex = slist[0]

                if (start == -1 or (index - minindex) < (end - start)):
                    start = minindex
                    end = index
        return s[start:end+1]
                