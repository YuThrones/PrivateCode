# 这道题不是很理解为什么标hard，解法挺简单的，可能存在更快的解法？

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        count = 0
        last = None
        for num in nums:
            # print ('test', num, count ,last)
            if num - 1 == last:
                count += 1
            elif num == last:
                continue
            else:
                if count > res:
                    res = count
                count = 1
            last = num
        if count > res:
            res = count
        return res