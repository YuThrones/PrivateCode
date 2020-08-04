# 解题方式还是递归，子节点求出自己的解之后，父节点对应把它层数加1放置到对应层即可
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if (root is None):
            return []
        
        res = [[root.val]]
        left_res = self.levelOrder(root.left)
        right_res = self.levelOrder(root.right)        
        for index, sub_list in enumerate(left_res):
            if (len(res) <= index + 1):
                res.append([])
            for val in sub_list:
                res[index + 1].append(val)
            
        for index, sub_list in enumerate(right_res):
            if (len(res) <= index + 1):
                res.append([])
            for val in sub_list:
                res[index + 1].append(val)
            
        return res