# 这个的思路是通过递归来进行不同路径的搜索，加上重复结果的记忆，优先搜索前进量较大，也就是预期较短的分支
# 需要注意的就是对 * 符号的处理
class Solution:
    check_set = {}
    def isMatch(self, s: str, p: str) -> bool:
        print ("IsMatch |", s, "|", p)
        if ((s, p) in self.check_set):
            return self.check_set[(s, p)]
        if (len(p) == 0):
            if (len(s) == 0):
                self.check_set[(s, p)] = True
                return True
            else:
                self.check_set[(s, p)] = False
                return False
        
        if (len(s) == 0):
            if (len(p) > 1 and p[1] == "*"):
                result = self.isMatch(s, p[2:])
                self.check_set[(s, p)] = result
                return result
            else:
                self.check_set[(s, p)] = False
                return False
            
        if (p[0] == "." or p[0] == s[0]):
            if (len(p) > 1 and p[1] == "*"):
                result = self.isMatch(s[1:], p[2:]) or self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
                self.check_set[(s, p)] = result
                return result
            else:
                result = self.isMatch(s[1:], p[1:])
                self.check_set[(s, p)] = result
                return result
        else:
            if (len(p) > 1 and p[1] == "*"):
                result = self.isMatch(s, p[2:])
                self.check_set[(s, p)] = result
                return result
            else:
                self.check_set[(s, p)] = False
                return False

            