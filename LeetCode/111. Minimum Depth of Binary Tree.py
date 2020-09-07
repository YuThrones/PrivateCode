# 比较简单，只需要注意必须是叶子结点才算深度，不能直接两个子树取最小值，空子树不进行计算。

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if (root is None):
            return 0
        
        if (root.left is None):
            return self.minDepth(root.right) + 1
        
        if (root.right is None):
            return self.minDepth(root.left) + 1
        
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        