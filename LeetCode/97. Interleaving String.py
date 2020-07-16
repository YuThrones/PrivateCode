# 最初是直接用递归解决，但是在大数据的时候运行太慢，于是在递归基础上加了重复存储记录
看了下讨论，是可以使用动态规划解决的

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        self.s1 = s1
        self.s2 = s2
        self.s3 = s3
        self.record = {}
        
        return self.cal(0, 0, 0)
    
    def cal(self, index1, index2, index3):
        # print("cal", index1, index2, index3, self.s1[index1:], self.s2[index2:], self.s3[index3:])
        if (index1 == len(self.s1) and index2 == len(self.s2) and index3 == len(self.s3)):
            return True
        
        if ((index1, index2, index3) in self.record):
            return self.record[(index1, index2, index3)]
        
        if (index3 >= len(self.s3)):
            return False
        
        if (index1 < len(self.s1) and self.s1[index1] == self.s3[index3]):
            sub = self.cal(index1 + 1, index2, index3 + 1)
            if (sub):
                return True
            
        if (index2 < len(self.s2) and self.s2[index2] == self.s3[index3]):
            sub = self.cal(index1, index2 + 1, index3 + 1)
            if (sub):
                return True
        
        self.record[(index1, index2, index3)] = False
        return False


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        record = {}
        len1 = len(s1)
        len2 = len(s2)
        len3 = len(s3)
        if (len1 + len2 != len3):
            return False
        for i in range(len1 + 1):
            record[i] = {}
            for j in range(len2 + 1):
                if (i == 0 and j == 0):
                    record[i][j] = True
                elif (i == 0):
                    record[i][j] = (record[i][j - 1] and (s2[j - 1] == s3[i + j - 1]))
                elif (j == 0):
                    record[i][j] = (record[i - 1][j] and (s1[i - 1] == s3[i + j - 1]))
                else:
                    record[i][j] = (record[i][j - 1] and (s2[j - 1] == s3[i + j - 1])) or (record[i - 1][j] and (s1[i - 1] == s3[i + j - 1]))           
        # print("result", record)
        return record[len1][len2]