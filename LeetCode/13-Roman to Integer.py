# 这个解法是从讨论中看到的，比我自己要快一点，核心是每个特殊表示最多只可能出现一次，所以提前把特殊表示会导致的增加量减掉，后面遍历的时候可以统一逻辑处理，不过不能理解的是这样应该算是多次遍历，为什么会比单次遍历然后做判断的速度要快，后续有空再想想
class Solution:
    symbol_value = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000,
    }
    def romanToInt(self, s: str) -> int:
        result = 0
        if(s.find("IV")!=-1):
            result-=2
        if(s.find("IX")!=-1):
            result-=2
        if(s.find("XL")!=-1):
            result-=20
        if(s.find("XC")!=-1):
            result-=20
        if(s.find("CD")!=-1):
            result-=200
        if(s.find("CM")!=-1):
            result-=200
        
        for sub in s:
            result += self.symbol_value[sub]
    
        return result
            