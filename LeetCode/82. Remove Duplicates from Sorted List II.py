# 主要是要留一个指向上一个节点的指针，还有记录上个节点是否重复过了，通过这两个判断当前节点以及上一个节点是否可以加入新的节点链表
# 需要注意的是链表结尾要单独判断一下，注意边界条件即可
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if (head == None):
            return None
        leftDiff = ListNode(head.val)
        current = head.next
        repeat = False
        result = None
        last = result
        while(current != None):
            if (current.val != leftDiff.val):
                if (not repeat):
                    if (last != None):
                        last.next = leftDiff
                    if (not result):
                        result = leftDiff
                    last = leftDiff
                leftDiff = ListNode(current.val)
                repeat = False
            else:
                repeat = True
            current = current.next
        if (current == None and repeat == False):
            if (last != None):
                last.next = leftDiff
            if (not result):
                result = leftDiff
        return result
                