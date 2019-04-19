# 主要思路是根据根据前两个数计算出第三个数，然后搜索第三个数在不在列表中，根据这个思路做剪枝和优化，主要的措施有
# 1.把列表从小到大排列
# 2.把每个数的最后一次出现的索引存放在字典中
# 3.从前到后遍历列表，从第一个开始穷举第一个数，对于大于0的第一个数进行剪枝
# 4.对于跟上一个数字一样的直接剪枝（这个优化能减少很多重复检查）
# 5.对重复结果进行筛除
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if (len(nums) < 3):
            return []
        nums.sort()
        result = []
        repeat_set = {}
        result_set = {}
        for i in range(len(nums)):
            repeat_set[nums[i]] = i
        
        last_first_num = None
        for first_index in range(len(nums) - 1):
            if (last_first_num == nums[first_index]):
                continue
            last_first_num = nums[first_index]
            if (nums[first_index] > 0):
                break
                                
            for second_index in range(first_index + 1,len(nums)):     
                total = nums[first_index] + nums[second_index]
                if (total > 0):
                    break
                third = -total
                if (third in repeat_set):

                    if (not (nums[first_index], nums[second_index], third) in result_set):
                        if (repeat_set[third] > second_index):
                            result.append((nums[first_index], nums[second_index], third))
                            result_set[(nums[first_index], nums[second_index], third)] = 1
        return result
        