# 总体思路是先算出每个循环周期有多少个字符，然后根据在原字符串中的索引算出在新字符串的第几行，然后拼接起来
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if (numRows == 1):
            return s
        period = numRows * 2 - 2
        length = len(s)
        result = []
        # print (period)
        for i in range(numRows):
            result.append("")
        for i in range(length):
            period_index = i % period
            row = 0
            if (period_index < numRows):
                row = period_index % numRows
            else:
                row = numRows - (period_index % numRows) - 2
            # print (i, s[i], period_index, row)

            result[row] += s[i]
        # print (result)
        return "".join(result)