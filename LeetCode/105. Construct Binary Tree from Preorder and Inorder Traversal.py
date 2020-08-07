# 一开始想确定左子树的inorder最后一个值索引来计算右子树的preoder第一个索引
# 后面一想不用这么麻烦，通过preorder第一个值确定root节点，然后inorder中搜索找到root，就可以划分为左右子树
# 根据左右子树的大小，就可以在preorder中直接划分
# 不过目前运算效率较低，估计是因为大量使用了分片，可以考虑用索引的方式来重写
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        length = len(preorder)
        if (length == 0):
            return None
        rootval = preorder[0]
        root = TreeNode(rootval)
        
        left_count = 0
        for index in range(length):
            if (inorder[index] == rootval):
                break
            left_count = left_count + 1
        
        root.left = self.buildTree(preorder[1:left_count+1], inorder[:left_count])
        root.right = self.buildTree(preorder[left_count+1:], inorder[left_count+1:])
        return root

        
# 改用索引之后速度提高了一倍左右，但是还是不够快
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        length = len(preorder)
        return self.build(preorder, inorder, 0, length, 0, length)
    
    def build(self, preorder, inorder, pre_start, pre_end, in_start, in_end):
        if (pre_end == pre_start):
            return None
        
        rootval = preorder[pre_start]
        root = TreeNode(rootval)
        
        left_count = 0
        for index in range(in_start, in_end):
            if (inorder[index] == rootval):
                break
            left_count = left_count + 1
        
        root.left = self.build(preorder, inorder, 
                                   pre_start + 1, 
                                   pre_start + 1 + left_count, 
                                   in_start, 
                                   in_start + left_count)
        
        root.right = self.build(preorder, inorder,
                                    pre_start + 1 + left_count, 
                                    pre_end, 
                                    in_start + 1 + left_count, 
                                    in_end)
        return root
        

        