# 这道题一开始自己没做出来，后面看了下讨论，思路就是如果这个树展开成为数组，那么交换第一个和最后一个不满足递增规律的数
# 实现就是用中序遍历找到这么两个不满足的树节点

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    first = None
    second = None
    prev = None
    
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.cal(root)
        # print("结果", self.first.val, self.second.val)
        temp = self.first.val
        self.first.val = self.second.val
        self.second.val = temp
    
    def cal(self, root):
        if (root is None):
            return
        
        self.cal(root.left)
        
        # print("打印", root.val, self.first, self.second, self.prev)
        
        if (self.first == None and (self.prev is not None and self.prev.val >= root.val)):
            self.first = self.prev
            
        if (self.first != None and (self.prev is not None and self.prev.val >= root.val)):
            self.second = root
            
        self.prev = root
        
        self.cal(root.right)

        
        