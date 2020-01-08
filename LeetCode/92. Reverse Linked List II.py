链表的倒置，主要注意边界条件，链表头和链表尾，倒置长度为1等。写的比较乱，应该可以整理一下缩短。
看了下答案，用的是递归，确实很巧妙，但是理解成本也不低，而且运行试了下，效率也没有更高，但是可以作为参考

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        index = 1
        cur = head
        last = None
        start = None
        
        while(cur != None):
            if (m == index):
                start = cur
                break
            index += 1
            last = cur
            cur = cur.next
        startindex = index
        cur = start
        tail = cur
        tailnext = cur.next
        prev = None
        while (index <= n):
            nextnode = cur.next
            if (index == n):
                tail = cur
                tailnext = nextnode
            cur.next = prev
            prev = cur
            cur = nextnode
            index += 1
        if (startindex == 1):
            head = tail
        else:
            last.next = tail
        start.next = tailnext
        return head
        
        
class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """

        if not head:
            return None

        left, right = head, head
        stop = False
        def recurseAndReverse(right, m, n):
            nonlocal left, stop

            # base case. Don't proceed any further
            if n == 1:
                return

            # Keep moving the right pointer one step forward until (n == 1)
            right = right.next

            # Keep moving left pointer to the right until we reach the proper node
            # from where the reversal is to start.
            if m > 1:
                left = left.next

            # Recurse with m and n reduced.
            recurseAndReverse(right, m - 1, n - 1)

            # In case both the pointers cross each other or become equal, we
            # stop i.e. don't swap data any further. We are done reversing at this
            # point.
            if left == right or right.next == left:
                stop = True

            # Until the boolean stop is false, swap data between the two pointers     
            if not stop:
                left.val, right.val = right.val, left.val

                # Move left one step to the right.
                # The right pointer moves one step back via backtracking.
                left = left.next           

        recurseAndReverse(right, m, n)
        return head