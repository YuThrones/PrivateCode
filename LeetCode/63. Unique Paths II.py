# 思路跟前一道题一样，但是多了一个障碍位置的判断，有障碍直接清0
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        rows = len(obstacleGrid)
        if (rows == 0):
            return 0
        cols = len(obstacleGrid[0])
        if (cols == 0):
            return 0
        count = [0] * cols
        count[0] = 1
        for row in range(rows):
            for col in range(cols):
                # print(count, row, col)
                if (obstacleGrid[row][col] == 1):
                    count[col] = 0
                else:
                    temp = count[col]
                    if (col - 1 >= 0):
                        temp += count[col-1]
                    count[col] = temp
        # print(count)
        return count[-1]
        
