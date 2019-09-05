# 思路比较简单，贪心算法，从前往后遍历，判断以前一位为终止点的和是否大于0，是则与当前位置的数字相加，就是当前位置为终止点的最大和，最后求出所有位置为终止点的最大和的最大值即可
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = nums[0]
        lastsum = nums[0]
        length = len(nums)
        for index in range(1, len(nums)):
            num = nums[index]
            currentsum = num
            if (lastsum > 0):
                currentsum += lastsum
            maxsum = max(maxsum, currentsum)
            lastsum = currentsum
        return maxsum