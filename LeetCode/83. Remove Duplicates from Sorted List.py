# 上道题的简化版，就是很奇怪为什么比较容易的放后面。。
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        last = result = None
        current = head
        while(current != None):
            if (last == None):
                result = last = ListNode(current.val)
            elif (last.val != current.val):
                last.next = ListNode(current.val)
                last = last.next
            current = current.next
        return result