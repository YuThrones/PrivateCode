// 典型的链表节点处理问题，注意头部加一个哨兵用于方便所有情况统一即可

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* last = new ListNode();
        last->next = head;
        ListNode* newHead = last;
        while(head) {
            if (head->val == val) {
                last->next = head->next;
            }
            else {
                last = head;
            }
            head = head->next;
        }
        return newHead->next;
    }
};