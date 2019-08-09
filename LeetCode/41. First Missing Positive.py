这道题的思路是看讨论里面一个C++的解法，比我用的遍历用字典记录重复要快一点点，主要思路就是遍历一次，把数字放到对应的位置上，然后重新遍历一次，返回第一个索引与数字不符的即可
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        length = len(nums)
        for index in range(length):
            num = nums[index]
            while (num <= length and num > 0 and nums[index] != nums[num-1]):
                nums[index], nums[num-1] = nums[num-1], nums[index]
                num = nums[index]

        for index in range(length):
            num = nums[index]
            if (index + 1 != num):
                return index + 1
        return length + 1
                