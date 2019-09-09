从前往后遍历，遇到第一个还没到达的节点，或者达到终点就返回结果
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_index = 0
        length = len(nums)
        for index, num in enumerate(nums):
            if (index > max_index):
                return False
            max_index = max(max_index, index + num)
            if (max_index >= length):
                return True
        return True