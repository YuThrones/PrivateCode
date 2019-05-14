# 主要思路思路是用之前的两列表合并，再加上二分法就可以得到较好的效率
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = cur = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 or l2
        return dummy.next
    
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if (len(lists) == 0):
            print ("error")
            return None
        if (len(lists) == 1):
            return lists[0]
        if (len(lists) == 2):
            return self.mergeTwoLists(lists[0], lists[1])
        length = len(lists)
        return self.mergeTwoLists(self.mergeKLists(lists[:length // 2]), self.mergeKLists(lists[length // 2:]))