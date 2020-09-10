# 使用上道题无额外空间的方式，主要就是注意判断子节点缺失的情况
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
        if (root is None):
            return None
        
        pre = root
        cur = None
        while(pre.left or pre.right):
            cur = pre
            while(cur):
                next_right = None
                next_node = cur.next
                while(next_node):
                    if (next_node.left):
                        next_right = next_node.left
                        break
                    elif (next_node.right):
                        next_right = next_node.right
                        break
                    else:
                        next_node = next_node.next
                
                if (cur.left):
                    if (cur.right):
                        cur.left.next = cur.right
                    elif (next_right):
                        cur.left.next = next_right
                
                if (cur.right):
                    cur.right.next = next_right
                    
                cur = cur.next
            next_pre = None
            while(pre):
                if (pre.left and (pre.left.left or pre.left.right)):
                    next_pre = pre.left
                    break
                elif (pre.right and (pre.right.left or pre.right.right)):
                    next_pre = pre.right
                    break
                else:
                    pre = pre.next
            if (next_pre):
                pre = next_pre
            else:
                break    
        return root