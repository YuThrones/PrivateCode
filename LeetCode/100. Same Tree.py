# 很简单的比较，只有左右子树都是一样的树，并且自身的值一致才是一样的树

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if (p == None and q == None):
            return True
        
        if (p == None or q == None):
            return False
        
        if (p.val != q.val):
            return False
        
        if (not self.isSameTree(p.left, q.left)):
            return False
        
        if (not self.isSameTree(p.right, q.right)):
            return False
        
        return True