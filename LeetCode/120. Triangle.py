# 思路比较简单，从倒数第二行往上遍历，每个位置的值等于他下面的两个位置的较小值加上自己的值，全部遍历完成最后返回第一行第一个数即可
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for index in range(len(triangle) - 2, -1, -1):
            row = triangle[index]
            for col_index, col in enumerate(row):
                row[col_index] = min(triangle[index + 1][col_index], triangle[index + 1][col_index + 1]) + col

        return triangle[0][0]