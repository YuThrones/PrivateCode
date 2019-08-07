# 简单的思路，从前往后枚举，然后递归求解子问题，只需要注意子问题只能够从当前的位置以及后面的数字选
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        if (target <= 0):
            return result
        for index, candidate in enumerate(candidates):
            if (candidate == target):
                result.append([candidate])
            elif (candidate < target):
                sub_result = self.combinationSum(candidates[index:], target - candidate)
                for sub in sub_result:
                    result.append([candidate] + sub)
        return result