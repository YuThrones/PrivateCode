# 主要思路是剪枝，从外往里搜索，最后一根木板如果大于第一根，那么这就是这个起始值的最优解，不需要再往里面搜索
# 如果一个起始值比前面起始值低，可以跳过这个起始值的计算
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_container = 0
        max_start = 0
        for start in range(len(height)):
            if (height[start] < max_start or height[start] * (len(height) - 1 - start) < max_container):
                continue
            max_start = height[start]
            max_height = 0
            for end in range(len(height) - 1, start, -1):
                if (height[end] < max_height):
                    continue
                max_height= height[end]
                result = min(height[start], height[end]) * (end - start)
                if (result > max_container):
                    max_container = result
                if (max_height >= height[start] or height[start] * (end - start) < max_container):
                    break
        return max_container