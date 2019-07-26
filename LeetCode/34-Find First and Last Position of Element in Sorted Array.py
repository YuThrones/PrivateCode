# 跟上道题一样，还是二分搜索，可以改二分搜索算法，直接找到左边界和右边界。也可以二分搜索找到一个值，然后线性向两端搜索，效率差不多
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start_index, end_index = -1, -1
        find_index = self.search(nums, target)
        length = len(nums)
        if (find_index != -1):
            start_index = end_index = find_index
            while(start_index - 1 >= 0 and nums[start_index - 1] == target):
                start_index -= 1
            while(end_index + 1 < length and nums[end_index + 1] == target):
                end_index += 1
        return [start_index, end_index]
        
    def search(self, nums, target):
        length = len(nums)
        if (length == 0):
            return -1
        mid_index = len(nums) // 2
        if (nums[mid_index] == target):
            return mid_index
        if (nums[mid_index] < target):
            right_index = self.search(nums[mid_index + 1:], target)
            if (right_index == -1):
                return right_index
            return mid_index + right_index + 1
        
        return self.search(nums[:mid_index], target)