# 简单的中序遍历

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if (root == None) :
            return []
        leftRes = self.inorderTraversal(root.left)
        leftRes.append(root.val)
        rightRes = self.inorderTraversal(root.right)
        return leftRes + rightRes