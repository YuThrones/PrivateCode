# 比较简单，就是递归，只需要注意判断子树上下边界即可，注意判断需要 if(min_val != None)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.isValid(root, None, None)
        
    def isValid(self, node, min_val, max_val):
        if (not node):
            return True
        
        if (min_val != None and node.val <= min_val):
            return False

        if (max_val != None and node.val >= max_val):
            return False
        
        return self.isValid(node.left, min_val, node.val) and self.isValid(node.right, node.val, max_val)
        