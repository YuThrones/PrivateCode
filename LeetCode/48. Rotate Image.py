# 比较简单，算好遍历边界，类似一个楼梯的形状，然后同时换四个位置就可以了
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for row in range(n // 2):
            for col in range(row, n - 1 - row):
                # print (row, col)
                matrix[row][col], matrix[col][n - 1 - row], matrix[n - 1 - row][n - 1 - col], matrix[n - 1 - col][row] = matrix[n - 1 - col][row],matrix[row][col], matrix[col][n - 1 - row], matrix[n - 1 - row][n - 1 - col]