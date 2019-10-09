# 思路跟上一题差不多，只是选择路径的条件从贪心变成了动态规划，只需要按照从上往下，从左往后的循环遍历顺序，从上面或者左边的值取一个最小值加到自己身上即可
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if (not grid):
            return  0
        rowcount = len(grid)
        if (rowcount == 0):
            return 0
        colcount = len(grid[0])
        if (colcount == 0):
            return 0
        for row in range(rowcount):
            for col in range(colcount):
                minsum = 0
                if (row - 1 >= 0):
                    minsum = grid[row-1][col]
                if (col - 1 >= 0):
                    if (minsum == 0 or minsum > grid[row][col-1]):
                        minsum = grid[row][col-1]
                grid[row][col] += minsum
        return grid[row][col]
