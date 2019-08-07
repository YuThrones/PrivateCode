跟上道题思路差不多，需要注意两个地方，一是求解子问题的时候不能包括当前索引，二是从前往后遍历的时候要注意记录最后一个搜索的数字，已经搜索过的不重复搜索。
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        return self.combinationSum(candidates, target)
        
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        if (target <= 0):
            return result
        last = None
        for index, candidate in enumerate(candidates):
            if (last == candidate):
                continue
            if (candidate == target):
                result.append([candidate])
            elif (candidate < target):
                sub_result = self.combinationSum(candidates[index+1:], target - candidate)
                for sub in sub_result:
                    result.append([candidate] + sub)
            last = candidate
        return result