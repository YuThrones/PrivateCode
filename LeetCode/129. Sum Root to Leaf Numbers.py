# 核心就是要把当前节点的值传入递归，根据每个递归乘以10

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        def seek(rootval, node):
            # print ('打印', rootval, node)
            if node is None:
                return rootval
            if node.left is None and node.right is None:
                return rootval + node.val
            leftval = 0 if node.left is None else seek((rootval + node.val) * 10, node.left)
            rightval = 0 if node.right is None else seek((rootval + node.val) * 10, node.right)
            return leftval + rightval
        
        return seek(0, root)