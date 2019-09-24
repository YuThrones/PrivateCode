# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# 思路是第一次先遍历，算出这个列表的长度并找到尾结点，第二次遍历找到要移动的节点的上一个节点，然后整个移动过去即可，唯一需要注意的就是k要求余，避免重复操作多次
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if (head == None or head.next == None):
            return head
        first = head
        count = 1
        current = head
        while (current.next != None):
            count += 1
            current = current.next
        end = current
            
        k %= count
        if (k == 0):
            return head
        current = head
        index = 0
        while (index < count - k -1):
            current = current.next
            index += 1
        # print (current)
        next_head = current.next
        current.next = None
        end.next = head
        return next_head
        
            