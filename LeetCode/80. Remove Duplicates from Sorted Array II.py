# 很简单，因为是已经有序的，从前往后，记录最后一个检查的数，统计重复数字，然后把没有超过次数的加入新列表，然后修改旧列表为新列表即可。
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        repeat_count = 0
        count = 0
        last = None
        new_list = []
        for num in nums:
            if (num != last):
                last = num
                repeat_count = 1
                count += 1
                new_list.append(last)
            else:
                if (repeat_count < 2):
                    count += 1
                    new_list.append(last)
                repeat_count += 1
                
        nums[0:] = new_list
        return count