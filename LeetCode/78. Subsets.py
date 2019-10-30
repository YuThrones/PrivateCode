# 很简单的递归，也可以用递推处理
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        if (len(nums) == 0):
            return [[]]
        subresult = self.subsets(nums[1:])
        for sub in subresult:
            result.append([] + sub)
            result.append([nums[0]] + sub)
        return result