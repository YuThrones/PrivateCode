这道题初看很难，一开始以为要尝试枚举所有情况遍历，后面画了一下，其实只是一个递归求解的问题
把原字符串设为S1，新字符串设为S2，从前往后遍历，找一个分隔点，把S1分隔为两份，然后对应的从前往后或者从后往前分隔S2
如果能够满足 S1前与S2前 以及S1后和S2后 的子问题递归求解为真，或者 S1前与S2后 以及S1后与S2前 的子问题为真，那么就有解
如果遍历之后都找不到答案，整个问题无解
最小的子问题是只有一个字符的时候，只需要判断字符是否相等即可，不过这样效率还不够高，因此需要剪枝
长度不相等直接返回false
字符串中各个字符的数量不同直接返回false，避免深层搜索，能有效提高效率
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        # print(s1, s2)
        if (len(s1) != len(s2)):
            return False
        if (s1 == s2):
            return True
        if (len(s1) == 1):
            return False
        
        def checkAdd(s, sub):
            if (not sub in s):
                s[sub] = 0
            s[sub] += 1
        
        def checkSub(s, sub):
            s[sub] -= 1
            if (s[sub] == 0):
                s.pop(sub)
        
        record1 = {}
        rerecord1 = {}
        record2 = {}
        rerecord2 = {}
        for index in range(len(s1) - 1):
            # print(s1, s2, index, record1, record2, rerecord1, rerecord2)
            if (s1[index] != s2[index]):
                str1 = s1[index]
                str2 = s2[index]
                if (str1 in record1):
                    checkSub(record1, str1)
                else:
                    checkAdd(record2, str1)
                if (str2 in record2):
                    checkSub(record2, str2)
                else:
                    checkAdd(record1, str2)      
                        
            if (len(record1) == 0 and len(record2) == 0):
                if (self.isScramble(s1[:index + 1], s2[:index + 1]) and self.isScramble(s1[index + 1:], s2[index + 1:])):
                    return True
                
            if (s1[index] != s2[-index - 1]):
                str1 = s1[index]
                str2 = s2[-index - 1]
                if (str1 in rerecord1):
                    checkSub(rerecord1, str1)
                else:
                    checkAdd(rerecord2, str1)
                if (str2 in rerecord2):
                    checkSub(rerecord2, str2)
                else:
                    checkAdd(rerecord1, str2) 

            if (len(rerecord1) == 0 and len(rerecord2) == 0):
                if (self.isScramble(s1[:index + 1], s2[-index-1:]) and self.isScramble(s1[index + 1:], s2[:-index-1])):
                    return True
        return False
    