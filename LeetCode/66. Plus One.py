# 很简单，记得处理进位就行
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        add = 1
        length = len(digits)
        for i in range(length - 1, -1, -1):
            if (add == 0):
                break
            digits[i] += 1
            if (digits[i] >= 10):
                digits[i] -= 10
                add = 1
            else:
                add = 0
        if (add == 1):
            digits.insert(0, 1)
        return digits