# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        nodeList = []
        # prev = None
        cur = head
        while (cur != None):
            nodeList.append(cur)
            # cur.pre = prev
            # prev = cur
            cur = cur.next
        length = len(nodeList)

        removeNode = nodeList[-n]
        prevNode = None
        if (length > n):
            prevNode = nodeList[-n-1]
        nextNode = removeNode.next
        if (prevNode != None):
            prevNode.next = nextNode
        if (length == 1):
            return None
        if (length == n):
            return nodeList[1]
        return nodeList[0]