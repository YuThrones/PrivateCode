# 复杂度为O(n),是从网上搜索Manacher's Algorithm然后用python自己编码，参考 http://www.cnblogs.com/grandyang/p/4475985.html
class Solution:
    def longestPalindrome(self, s: str) -> str:
        news = "#" + "#".join(s) + "#"
        mx = 0
        mid = 0
        resLen = 0
        ridus = 0
        p = []
        length = len(news)
        # print (news)
        for i in range(length):
            p.append(1)
            p[i] = min(mx - i, p[mid * 2 - i]) if mx > i else 1
            while(i + p[i] < length and i - p[i] >= 0 and news[i + p[i]] == news[i - p[i]]):
                p[i] += 1
            # print (i, p[i], mx)
            if (i + p[i] > mx):
                mx = i + p[i]
                mid = i
                
            if (p[i] > ridus):
                ridus = p[i]
                resCen = i
        # print (">>>>>>")
        # print (ridus, resCen)
        start = (resCen - ridus + 1) // 2        
        end = (resCen + ridus - 2) // 2
        # print (start, end)
        return s[start:end + 1]