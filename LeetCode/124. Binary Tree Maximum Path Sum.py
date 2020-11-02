# 这道题想到的思路比较简单粗暴，通过分治的方式来处理，每个子问题返回两个值，一个是从下往上到子节点为止的线性链表的总和，另一个是子节点的最大路径值，可能同时涵盖子节点的左右子树
# 节点的最大路径值是左右两个子节点的最大路劲值，或者左右两个子节点的最大线性链表和加上父节点，或者父节点本身的值(在没有左右子节点或者节点路径和小于0的时候)
# 最终问题的解就是根节点的最大路径值（total）。

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        line, total = self.cal(root)
        return total
    
    def cal(self, root):
        if root is None:
            return None, None
        
        leftLine = None
        leftTotal = None
        rightLine = None
        rightTotal = None
        
        if root.left is not None:
            leftLine, leftTotal = self.cal(root.left)
            
        if root.right is not None:
            rightLine, rightTotal = self.cal(root.right)
            
        leftLine = leftLine if leftLine else 0
        leftTotal = leftTotal if leftTotal else root.val
        rightLine = rightLine if rightLine else 0
        rightTotal = rightTotal if rightTotal else root.val
        
        rootLine = max(0, max(leftLine, rightLine)) + root.val
            
        rootTotal = max(leftTotal, rightTotal)
        rootTotal = max(rootTotal, leftLine + rightLine + root.val)
        rootTotal = max(rootTotal, rightLine + root.val)
        rootTotal = max(rootTotal, leftLine + root.val)
        rootTotal = max(rootTotal, root.val)
        return rootLine, rootTotal
            