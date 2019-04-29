# 这道题的核心思路是递归，把多个数的和问题最后分解为两个数的和问题的基本形态，并且通过剪枝去除大量无用的搜索分支
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        results = []
        # print (nums)
        def findSum(l, r, target, N, result):
            # print ("finsSum", nums[l:r+1], target, N, result)
            if ((r-l+1 < N) or (N < 2) or (target < nums[l] * N) or (target > nums[r] * N)):
                return
            
            if (N == 2):
                while (l < r):
                    s = nums[l] + nums[r]
                    if (s < target):
                        l += 1
                    elif (s > target):
                        r -= 1
                    else:
                        results.append(result + [nums[l], nums[r]])
                        l += 1
                        while(l < r and nums[l] == nums[l-1]):
                            l += 1
            else:
                for i in range(l, r+1):
                    if (i == l or (i > l and nums[i-1] != nums[i])):
                        findSum(i+1, r, target - nums[i], N - 1, result + [nums[i]])
        
        findSum(0, len(nums) - 1, target, 4, [])
        return results