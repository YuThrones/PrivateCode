# 跟上一道题的思路差不多，只是不是返回True和False，而是直接记录结果返回，稍加修改即可

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if (root is None):
            return []
        
        if (root.left is None and root.right is None):
            if (root.val == sum):
                return [[root.val]]
            else:
                return []
            
        subsum = sum - root.val
        left_res = self.pathSum(root.left, subsum)
        right_res = self.pathSum(root.right, subsum)
        
        res = []
        
        for sub in left_res:
            res.append([root.val] + sub)
            
        for sub in right_res:
            res.append([root.val] + sub)
            
        return res
            