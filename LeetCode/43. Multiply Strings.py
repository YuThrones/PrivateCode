# 主要就是把乘法计算过程代码化，注意边界条件即可。
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        len1 = len(num1)
        len2 = len(num2)
        result = [0] * (len1 + len2)
        pos = len1 + len2 - 1
        
        for n1 in reversed(num1):
            temp_pos = pos
            for n2 in reversed(num2):
                mul = int(n1) * int(n2) + result[temp_pos]
                result[temp_pos] = mul % 10
                result[temp_pos - 1] += mul // 10
                temp_pos -= 1
            pos -= 1
                
        p = 0
        for index in range(len1 + len2 - 1):
            if (result[index] != 0):
                break
            p += 1
                
        return "".join(map(str, result[p:]))