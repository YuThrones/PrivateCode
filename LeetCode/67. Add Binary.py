# 思路应该是比较简单的，逆序按位加，注意进位就行
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if (len(b) > len(a)):
            a, b = b, a
        lena = len(a)
        lenb = len(b)
        carry = 0
        result = []
        for i in range(1, lena+1):
            addsum = int(a[-i]) + carry
            if (i <= lenb):
                addsum += int(b[-i])
            if (addsum >= 2):
                addsum -= 2
                carry = 1
            else:
                carry = 0
            result.append(str(addsum))
        if (carry == 1):
            result.append("1")
        return "".join(reversed(result))