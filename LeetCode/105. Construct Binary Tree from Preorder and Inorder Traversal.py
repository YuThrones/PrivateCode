# 一开始想确定左子树的inorder最后一个值索引来计算右子树的preoder第一个索引
# 后面一想不用这么麻烦，通过preorder第一个值确定root节点，然后inorder中搜索找到root，就可以划分为左右子树
# 根据左右子树的大小，就可以在preorder中直接划分
# 不过目前运算效率较低，估计是因为大量使用了分片，可以考虑用索引的方式来重写

# 看了下其他答案的分析，发现这里还有个问题，就是如果树是一条线的话，那么在inorder中搜索rootval的效率极低，复杂度会达到n的平方

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
        
# 论坛看到的解法，有点难想到，但是确实很简单，速度也要快一倍左右，思路就是进行前序遍历，在前序遍历过程中拆分inorder数组传进去，不断pop前序数组
class Solution:
    def buildTree(self, preorder, inorder):
        if inorder:
            ind = inorder.index(preorder.pop(0))
            root = TreeNode(inorder[ind])
            root.left = self.buildTree(preorder, inorder[0:ind])
            root.right = self.buildTree(preorder, inorder[ind+1:])
            return root


# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map
# 这是在论坛看到的最难懂，但是效率也最高的解法，有几个核心点：
# 第一，用普通的分左右子树然后递归，遇到树成一条直线的极度不均匀形状，会导致搜索划分点的消耗很高，复杂度为n的平方
# 第二，每一层都传入父节点的值作为停止判断，向左子树搜索的时候，界限是当前层root节点的值，在中序搜索中遇到这个值代表左子树已经生成完，搜索右子树则应该使用父节点传下来的stop的值判断
# 第三，把两个数组都先reverse，使得pop的时候复杂度是1而不是n
class Solution:
    def buildTree(self, preorder, inorder):
        def build(stop):
            if inorder and inorder[-1] != stop:
                root = TreeNode(preorder.pop())
                root.left = build(root.val)
                inorder.pop()
                root.right = build(stop)
                return root
        preorder.reverse()
        inorder.reverse()
        return build(None)

        