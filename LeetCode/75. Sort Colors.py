# 这道题第一眼看上去好像是让你自己写排序，事实上如果要单次遍历，场数空间，只需要记录三个数字各出现多少次，重新组织就行了。。
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        record = [0] * 3
        for num in nums:
            record[num] += 1
        nums[:record[0]] = [0] * record[0]
        nums[record[0]:record[0]+record[1]] = [1] * record[1]
        nums[record[0]+record[1]:] = [2] * record[2]        