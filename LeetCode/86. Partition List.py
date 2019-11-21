# 这道题思路是很简单的，用两个列表记录小于分隔值的点和大于等于分隔值的点，然后拼接起来就可以了
# 需要注意的是可以先用两个哑节点来记录两个列表的头，最后拼接前再去掉，这样不用处理特殊情况，判断少很多，效率更高

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        lesshead = lesslist = ListNode(0)
        greaterhead = greaterlist = ListNode(0)
        while(head != None):
            if (head.val < x):
                lesslist.next = ListNode(head.val)
                lesslist = lesslist.next
            else:
                greaterlist.next = ListNode(head.val)
                greaterlist = greaterlist.next
            head = head.next
        greaterhead = greaterhead.next
        lesslist.next = greaterhead
        lesshead = lesshead.next
        return lesshead