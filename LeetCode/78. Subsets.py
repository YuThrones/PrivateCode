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

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        if (len(nums) == 0):
            return result
        for num in nums:
            for index in range(len(result)):
                sub = result[index]
                new_list = sub[:]
                new_list.append(num)
                result.append(new_list)
        return result