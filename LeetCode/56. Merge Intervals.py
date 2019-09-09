# 思路比较简单，按起始点排序，然后从前往后遍历，终止点能连上就合并，不能就储存起来，用下一个开始继续查询
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if (len(intervals) < 2):
            return intervals
        intervals.sort(key=lambda x:x[0])
        current = None
        result = []
        for pair in intervals:
            if (not current):
                current = pair
                continue
            if (current[1] >= pair[0]):
                current[1] = max(current[1], pair[1])
            else:
                result.append(current)
                current = pair
        result.append(current)
        return result