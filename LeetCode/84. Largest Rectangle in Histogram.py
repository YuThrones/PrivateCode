# 一开始尝试了从每一个数往两边搜索，发现超时了，看了下其他人的做法，有一个优化空间
# 那就是从一开始先找到每一个索引左边和右边第一个比自己小的数，然后这两个数中间的部分就是以这个高度框起来的矩形
# 如果只是这样做，复杂度是一样的，这里一个关键点在于利用前面搜索的结果，如果左边的数比你大，那么他的左边界必然比你靠右，所以你可以从他的左边界开始向左搜索
# 这样子可以把复杂度降低很多，满足时间的要求
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        result = 0
        length = len(heights)
        if (length == 0):
            return result
        
        toleft = [0] * length
        toright = [0] * length
        toleft[0] = -1
        toright[-1] = length
        for i in range(1, length):
            p = i - 1
            while(p >= 0 and heights[p] >= heights[i]):
                p = toleft[p]
                
            toleft[i] = p
            
        for i in range(length - 2, -1, -1):
            p = i + 1
            while (p <= length-1 and heights[p] >= heights[i]):
                p = toright[p]
            toright[i] = p
        # print(toleft)
        # print(toright)
        for i in range(length):
            result = max(result, heights[i] * (toright[i] - toleft[i] - 1))
        return result