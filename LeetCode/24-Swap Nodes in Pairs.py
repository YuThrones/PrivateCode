# 思路很简单，直接从头遍历一次，然后改变节点的连接就行，加入哑节点简化情况即可
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dumpyNode = ListNode(0)
        dumpyNode.next = head
        first = dumpyNode
        last = dumpyNode
        cur = head
        while(cur != None):
            if (cur.next == None):
                break

            one = cur
            two = cur.next
            one.next = two.next
            two.next = one
            last.next = two
            last = one
            cur = one.next
        return first.next
            