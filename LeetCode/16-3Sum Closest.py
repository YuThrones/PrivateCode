# 这是O(n)复杂度的算法，总体思路是遍历第一个，然后从首尾两端逼近target
# 主要优化思想是在逼近之前先考虑两个极端情况，最大和最小值，如果target在最大和最小值之间的区间之外，直接看这两个值哪个更接近即可
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        length = len(nums)
        # print ("sort", nums)
        result = nums[0] + nums[1] + nums[2]
        for i in range(length - 2):
            start = i + 1
            end = length - 1
            minsum = nums[i] + nums[i+1] + nums[i+2]
            maxsum = nums[i] + nums[-1] + nums[-2]
            if (minsum > target):
                if (abs(minsum - target) < abs(result - target)):
                    result = minsum
                return result
            if (maxsum < target):
                if (abs(maxsum - target) < abs(result - target)):
                    result = maxsum
                continue
            while (start < end):
                total = nums[i] + nums[start] + nums[end]
                if (total > target):
                    end -= 1
                elif (total < target):
                    start += 1
                else:
                    return total
                if (abs(total - target) < abs(result - target)):
                    result = total
                
        return result