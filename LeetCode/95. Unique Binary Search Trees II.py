# 先把用到的所有数列出来，然后根据递归解决
# 看了下Java解法，其实可以动态规划，可以改下

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        treeList = []
        for i in range(n):
            value = i + 1
            treeList.append(value)
        if (len(treeList) == 0):
            return []
        return self.cal(treeList)
            
    def cal(self, inputList):
        if (len(inputList) == 0):
            return [None]
        treeList = []
        for index, value in enumerate(inputList[:]):
            leftList = self.cal(inputList[:index])
            rightList = self.cal(inputList[index+1:])
            for left in leftList:
                for right in rightList:
                    node = TreeNode(value, left, right)
                    treeList.append(node)
        return treeList
            
# 根据讨论中看到的Java解法改的，动态规划的解法，主要思路是通过把同样长度的连续数组的唯一树形状存储下来，减少递归引起的重复计算
# 很重要的一点在于clone的时候有一个offset，这样无论是[1,2,3]的排列还是[4,5,6]的排列，树的数目和形状是一样的，只需要加上3的offset就可以了
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        treeList = []
        treeList.append([])
        if (n == 0):
            return []
        treeList[0].append(None)
        
        for length in range(1, n + 1):
            treeList.append([])
            for j in range(length):
                for left in treeList[j]:
                    for right in treeList[length - j -1]:
                        node = TreeNode(j+1)
                        node.left = left
                        node.right = self.clone(right, j + 1)
                        treeList[length].append(node)
        return treeList[n]
                    
            
    def clone(self, node, offset):
        if (node == None):
            return None
        return TreeNode(node.val + offset, self.clone(node.left, offset), self.clone(node.right, offset))
        
            