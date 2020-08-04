# 其实跟上道题一样的，把上道题代码copy过来，计算完之后最后加一步把偶数层的列表倒过来即可
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        origin_res = self.levelOrder(root)
        length = len(origin_res)
        for index in range(length):
            if (index % 2 == 1):
                origin_res[index] = reversed(origin_res[index])
        return origin_res
        
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