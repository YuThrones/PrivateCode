# 跟前一道题思路一样，用二分搜索，只是这次数据结构是链表而不是数组，所以改用快慢指针实现。

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        return self.build(head, None)
            
        
    def build(self, head, stop):
        if (not head):
            return None
        if (head == stop):
            return None
        
        fast = head
        slow = head
        while (slow is not None and slow != stop):
            slow = slow.next
            if (slow is None or slow == stop):
                break
            
            fast = fast.next
            slow = slow.next
            
        root = TreeNode(fast.val)
        root.left = self.build(head, fast)
        root.right = self.build(fast.next, stop)
        return root