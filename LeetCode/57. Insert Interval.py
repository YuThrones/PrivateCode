直接加入新的间隔，用前一道题的算法就可以解决，不过效率比较低一点
如果在单次遍历中进行合并，可以减少不必要的比较，然后在最后排序一下，效率会更高一点
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        for interval in intervals:
            if (interval[0] >= newInterval[0] and interval[0] <= newInterval[1]) \
                or (interval[1] >= newInterval[0] and interval[1] <= newInterval[1]) \
                or (newInterval[0] >= interval[0] and newInterval[0] <= interval[1]) \
                or (newInterval[1] >= interval[0] and newInterval[1] <= interval[1]):                
                    newInterval[1] = max(newInterval[1], interval[1])
                    newInterval[0] = min(newInterval[0], interval[0])
            else:
                result.append(interval)
        result.append(newInterval)
        result.sort()
        return result