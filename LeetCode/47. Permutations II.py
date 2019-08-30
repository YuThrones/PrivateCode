# 在上一题基础上，在迭代的时候做一个记录和重复检测就可以了
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        if (len(nums) < 2):
            return [nums]
        record = {}
        for index, num in enumerate(nums):
            if (num in record):
                continue
            record[num] = True
            sub_result = self.permuteUnique(nums[:index] + nums[index+1:])
            for sub in sub_result:
                result.append([num] + sub)
        return result