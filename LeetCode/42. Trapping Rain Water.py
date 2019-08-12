# 这道题的解题思路是从前往后搜索，找到第一个大于0的作为起点，然后找到一个不小于它的作为终点，计算中间这部分的积水。计算完成后将起点的数值设置为终点索引，然后继续往后搜索
# 第一次遍历完成后，如果起点不等于数组最后一个，说明后半部分存在找不到终点的情况，这时候反过来搜索一遍，以最后的起点start作为终止符，反向搜索一遍即可
class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        if (length < 3):
            return 0
        result = 0
        start = None
        for index in range(length):
            if (start == None):
                if (height[index] > 0):
                    start = index
                continue
            if (height[index] >= height[start]):
                ave = min(height[start], height[index])
                for i in range(start + 1, index):
                    result += ave - height[i]
                start = index
        if (start != length - 1):
            end = None
            for index in range(length - 1, start - 1, -1):
                if(end == None):
                    if (height[index] > 0):
                        end = index
                    continue
                if (height[index] >= height[end]):
                    ave = min(height[end], height[index])
                    for i in range(end - 1, index,-1):
                        result += ave - height[i]
                    end = index
        return result