# 递归，如果两个子树都为平衡二叉树并且它们的高度差不大于1则当前树为平衡二叉树
# 用-1代表树不是平衡二叉树，然后递归计算即可

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        depth = self.check(root)
        return depth != -1
        
    def check(self, root):
        if (root is None):
            return 0
        leftdepth = self.check(root.left)
        if (leftdepth == -1):
            return -1      
        rightdepth = self.check(root.right)
        if (rightdepth == -1):
            return -1
        if (abs(leftdepth - rightdepth) > 1):
            return -1
        return max(leftdepth, rightdepth) + 1 