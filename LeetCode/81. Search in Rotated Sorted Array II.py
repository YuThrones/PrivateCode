# 这道题本质上还是二分搜索，只是因为有旋转的存在，可能要判断下左右两边是否存在旋转，有可能两边都要搜索
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if (len(nums) == 0):
            return False
        if (len(nums) == 1):
            return nums[0] == target
        length = len(nums)
        start = 0
        end = length - 1
        mid = length // 2
        if (nums[mid] == target):
            return True
        left = False
        right = False
        if ((nums[mid] > target) or ((nums[0] >= nums[mid]) and (target >= nums[0]))):
            left = self.search(nums[:mid], target)
        if ((nums[mid] < target) or ((nums[length - 1] <= nums[mid]) and (target <= nums[length - 1]))):
            right = self.search(nums[mid+1:], target)
        return left or right