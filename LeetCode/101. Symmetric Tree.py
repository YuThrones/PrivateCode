# 跟上一道题思路差不多，只是从检查相等变成了检查对称

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if (root is None):
            return True
        
        return self.checkMirror(root.left, root.right)

        
    def checkMirror(self, left, right):
        if (left is None and right is None):
            return True
        if (left is None or right is None):
            return False
        
        if (left.val != right.val):
            return False
        
        return self.checkMirror(left.left, right.right) and self.checkMirror(left.right, right.left)