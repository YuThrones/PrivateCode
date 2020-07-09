# 最开始的想法是直接用上道题的思路，然后结果返回的是数量就可以，但是实测会超时，因为不需要具体树的内容，所以可以简化上一题的算法 

class Solution:
    def numTrees(self, n: int) -> List[TreeNode]:
        treeList = []
        treeList.append(1)
        if (n == 0):
            return 0
        
        for length in range(1, n + 1):
            treeList.append(0)
            for j in range(length):
                left = treeList[j]
                right = treeList[length - j - 1]
                treeList[length] = treeList[length] + left * right
        return treeList[n]
                    