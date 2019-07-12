# 这道题总体的思路是贪心，从后往前遍历，检查每一个数，找到处于这个数右边的比他大的数中最小的一个
# 如果能找到这么一个数，那么将这个数与第一个数交换位置，然后将第一个数位置后面所有的数进行排序，就能满足条件
# 核心思想就是尽可能找到一个最靠后的位置，增加最少的数值，是下一个序列
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        has_change = False
        if(size <= 1):
            return
        
        for first_index in range(size - 2, -1, -1):
            find_index = None
            # print ("first", nums[first_index])
            for second_index in range(size - 1, first_index, -1):
                # print ("second", nums[second_index], find_index)
                if (nums[second_index] > nums[first_index]):
                    if (find_index == None or nums[second_index] < nums[find_index]):
                        find_index = second_index
            if (find_index != None):
                nums[first_index], nums[find_index] = nums[find_index], nums[first_index]
                has_change = True
                nums[first_index + 1:] = sorted(nums[first_index + 1:])
                break
        
        if (not has_change):
            nums.reverse()
        # print ("output", nums)
            
            