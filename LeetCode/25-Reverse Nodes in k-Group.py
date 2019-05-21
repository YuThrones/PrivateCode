# 单次遍历，一边遍历一边改变节点的顺序，注意边界即可

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if (head == None or k <= 1):
            return head
        dummy = ListNode(0)
        dummy.next = head
        count = 1
        first = dummy
        start = head
        end = head
        while(end != None):
            if (k == count):
                end_next = end.next
                new_start = end_next
                new_first = start
                while (end != start):
                    start_next = start.next
                    start.next = new_start
                    new_start = start
                    start = start_next                
                end.next = new_start
                new_start = end

                first.next = new_start
                first = new_first
                start = end = end_next
                count = 1
            else:
                end = end.next
                count += 1

        return dummy.next