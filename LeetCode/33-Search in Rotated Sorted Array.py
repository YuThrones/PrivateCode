# 核心思路依然是二分法，只是需要注意在分的时候因为有一部分旋转位置的存在，判断处在哪一段的时候还需要先检查这一段是否完全是升序排列
# 检查方法也很简单，对比首尾元素即可，因为旋转的那一部分是从前面挪到后面的，所以如果不是完全升序，最后一个元素肯定比第一个元素小
# 然后其他的按照二分法算索引即可
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        result = -1
        
        length = len(nums)
        if (length < 1):
            return result
        
        check_index = length // 2
        check_num = nums[check_index]
        if (check_num == target):
            result = check_index
        elif (check_num >= nums[0]):
            if (target >= nums[0] and target < check_num):
                result = self.search(nums[:check_index], target)
            elif (target <= nums[-1] or target > check_num):
                sub_result = self.search(nums[check_index+1:], target)
                if (sub_result != -1):
                    result = check_index + 1 + sub_result
        else:
            if (check_num < target and target <= nums[-1]):
                sub_result = self.search(nums[check_index+1:], target)
                if (sub_result != -1):
                    result = check_index + 1 + sub_result
            elif (target < check_num or target >= nums[0]):
                result = self.search(nums[:check_index], target)
        
        return result