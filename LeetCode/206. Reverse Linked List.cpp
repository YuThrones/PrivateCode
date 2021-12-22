// 简单的链表翻转，注意下节点的链接赋值顺序就行
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* last = NULL;
        ListNode* next = NULL;
        while(head != NULL) {
            next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        return last;
    }
    
};