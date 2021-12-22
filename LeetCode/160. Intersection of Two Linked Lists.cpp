// 遍历两次列表解决问题，第一次先找到各自的尾部，并且统计长度，判断是否为同一个尾部，如果不是肯定没交集，返回NULL
// 如果尾部相同，则从头部开始，较长的链表先遍历两个长度差值的绝对值，然后两个链表同时往下遍历，一旦出现相同点就是第一个相交点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        int lengthA = 0;
        int lengthB = 0;
        
        ListNode * curA, * curB;
        curA = headA;
        while(curA->next) {
            ++lengthA;
            curA = curA->next;
        }
        
        curB = headB;
        while(curB->next) {
            ++lengthB;
            curB = curB->next;
        }
        
        if (curA != curB) {
            return NULL;
        }
        
        curA = lengthA > lengthB ? headA : headB;
        curB = curA == headA ? headB : headA;
        int diff = abs(lengthA - lengthB);
        while (diff-- > 0) {
            curA = curA->next;
        }
        
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};