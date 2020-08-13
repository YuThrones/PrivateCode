# 跟上一道题类似，刚好实验一下讨论看到的做法，稍微有所不同的是，因为后序根节点就在最后一位，所以postorder无须reverse
# 同时由于pop后序事实上就是从右子树开始构建，因此遍历顺序与前序不同，inorder也无须reverse

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def build(stop):
            # print(inorder, postorder, stop)
            if (inorder and inorder[-1] != stop):
                root = TreeNode(postorder.pop())
                root.right = build(root.val)
                inorder.pop()
                root.left = build(stop)
                return root
        
        return build(None)