# 思路还是分治，先把左子树变成一个链表，然后把右子树放到左子树最后一个节点的后面，然后用左子树替代右子树的位置
# 需要注意的就是各种None的情况的处理，左子树为空时只需要把右子树排成链表并返回右子树最后一个节点即可，不需要额外的替换节点
# 右子树为空时也只需要修改左子树并返回最后一个节点

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.convert(root)
        
    def convert(self, root):
        if (root is None):
            return None
        
        if (root.left is None and root.right is None):
            return root
        
        right_end = self.convert(root.right)
        if (root.left is None):
            return right_end
        
        left_end = self.convert(root.left)
        left_end.right = root.right
        root.right = root.left
        root.left = None
        
        if (right_end is not None):
            return right_end
        else:
            return left_end
            
        