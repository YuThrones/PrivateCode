# 思路是先进行一次搜索，用一个列表把对应层次的节点都存起来，搜索完成后再进行连接，但是这种做法需要额外的N个空间进行存储

# 看了下讨论，事实上有不需要存储的方案，先保证上一层的节点都接连完毕，然后开始连接新的一层
# 从上一层的第一个节点开始，先把自己的两个子节点连接起来，然后把自己的next节点的left节点连接到自己的right节点的next上面
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        record = []
        self.fill(record, root, 0)
        
        for node_list in record:
            last_node = None
            for node in node_list:
                if (last_node is not None):
                    last_node.next = node
                last_node = node
            last_node.next = None
        
        return root
        
    def fill(self, record, root, depth):
        if (root is None):
            return
        
        if (len(record) <= depth):
            record.append([])
            
        record[depth].append(root)
        self.fill(record, root.left, depth + 1)
        self.fill(record, root.right, depth + 1)        


# 无须额外存储的解法如下
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if (not root):
            return root
        pre = root
        cur = None
        while(pre.left):
            cur = pre
            while(cur):
                cur.left.next = cur.right
                if (cur.next is not None):
                    cur.right.next = cur.next.left
                cur = cur.next
            pre = pre.left
        return root