# 思路比较简单，选择一个数，然后剩下的递归传入函数，可能的优化就是看看能不能改成循环
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        if (len(nums) < 2):
            return [nums]
        for index, num in enumerate(nums):
            sub_result = self.permute(nums[:index] + nums[index+1:])
            for sub in sub_result:
                result.append([num] + sub)
        return result