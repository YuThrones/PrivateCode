# 还是简单的二分搜索，注意边界条件即可
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        length = len(nums)
        return self.build(nums, 0, length)
        
    def build(self, nums, start, end):
        if (start >= end):
            return None
        
        mid = (start + end) // 2
        root = TreeNode(nums[mid])
        root.left = self.build(nums, start, mid)
        root.right = self.build(nums, mid + 1, end)
        return root