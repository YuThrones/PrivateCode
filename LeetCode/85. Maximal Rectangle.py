# 这道题比较难，一开始有想到用动态规划，但是思路错了，一开始是想通过把矩形的面积分为四块，然后递归求解，但是实测效率不行
# 看了下其他人的解答，发现思路走错了，其实应该是在最基础的做法上面做优化，遍历每一行，用直方图的做法来算，用一个位置的直方图高度作为矩形的高，
# 然后往两边延伸，直到遇到比他矮的，当选择的高度与最大矩形高度一致时算出来的就是最大矩形的面积
# 在这个基础上做动态规划的思考，利用上一行每个位置左边界和右边界还有这一行当前的左边界和右边界来计算当前位置的左边界和右边界
# https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution ，做法在这个回答里面
# 其实这个左边界left和右边界right，就是满足对于选定的row,col，任意 left <= k < right，都有matrix[row][k] >= matrix[row][col]
# 本质上还是直方图的思路，只是用了动态规划之后显得比较难以理解，跟84题对照着看就会发现事实上是一样的，只是变成了多行的问题。
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        rowlen = len(matrix)
        if (rowlen == 0):
            return 0
        collen = len(matrix[0])
        if (collen == 0):
            return 0
        result = 0
        left = [0] * collen
        right = [collen] * collen
        height = [0] * collen
        
        for row in range(rowlen):
            curleft = 0
            curright = collen
            for col in range(collen):
                if (matrix[row][col] == "1"):
                    left[col] = max(left[col], curleft)
                else:
                    left[col] = 0
                    curleft = col + 1
                    
            for col in range(collen - 1, -1, -1):
                if (matrix[row][col] == "1"):
                    right[col] = min(right[col], curright)
                else:
                    right[col] = collen
                    curright = col
                    
            for col in range(collen):
                if (matrix[row][col] == "0"):
                    height[col] = 0
                else:
                    height[col] += 1
                result = max(result, (right[col] - left[col]) * height[col])
        return result
