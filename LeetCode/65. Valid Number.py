# 这道题的解法是看网上一个Java的版本改的，一开始我自己是想是不是应该用简单的语法解析，但是看了下网上提供的输入样本，跟我想的不太一样，很多看似不合理的都判为真，所以不需要那么复杂
# 只需要对于.、 e、 +-的先后以及互斥关系做好判断就行
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        s.replace(" ", "")
        eSeen = False
        dotSeen = False
        numberSeen = False
        numberAfterE = False
        for i, string in enumerate(s):
            if (string in "0123456789"):
                numberSeen = True
                numberAfterE = True
            elif (string == "."):
                if (eSeen or dotSeen):
                    return False
                dotSeen = True
            elif (string == "e"):
                if (eSeen or not numberSeen):
                    return False
                eSeen = True
                numberAfterE = False
            elif (string in "+-"):
                if (i != 0 and (i-1 < 0 or s[i-1]!="e")):
                    return False
            else:
                return False
        return numberSeen and numberAfterE
        