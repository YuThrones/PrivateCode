# 这道题的思路在于从第一个位置开始，搜索能够达到的所有位置，然后找到这些位置中预期能走到的最远的那个，选择这个作为下一个起点，继续搜索，这样可以在单次遍历中得到结果
class Solution:
    def jump(self, nums: List[int]) -> int:
        length = len(nums)
        if (length < 2):
            return 0
        count = 0
        current_max = 0
        i = 0
        next_max = 0
        while (current_max - i + 1 > 0):
            count += 1
            while(i <= current_max):
                next_max = max(next_max, nums[i] + i)
                if (next_max >= length-1):
                    return count
                i += 1
            current_max = next_max
        return 0
                