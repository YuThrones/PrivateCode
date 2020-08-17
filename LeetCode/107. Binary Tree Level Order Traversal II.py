# 把之前levelorder的答案reverse一下就可以了

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        level_order = self.levelOrder(root)
        level_order.reverse()
        return level_order
        
        
    def levelOrder(self, root):
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