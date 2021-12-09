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
// 这道题说白了就是手写一遍大数加法，注意下边界条件即可
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* cur = NULL;
        int carry = 0;
        int n1, n2, n3;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            n1 = n2 = n3 = 0;
            if (l1 != NULL) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                n2 = l2->val;
                l2 = l2->next;
            }
            n3 = n1 + n2 + carry;
            carry = n3 / 10;
            ListNode* node = new ListNode(n3 % 10);
            if (head == NULL) {
                head = node;
            }
            if (cur != NULL) {
                cur->next = node;
            }
            cur = node;
        }
        return head;
    }
};