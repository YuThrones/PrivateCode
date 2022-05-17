// 最容易想到的办法就是vector存储逆序对比，但是一看还有空间限制，于是想到原链表反序对比，不过速度有点慢
// 对比了一下最快答案，复杂度是差不多的，稍微慢一点，实现细节可能有点差距

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* last = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        last->next = nullptr;
        ListNode* tail = reverse(slow);
        while(head && tail) {
            if (head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode* next = head->next;
        ListNode* newHead = reverse(next);
        next->next = head;
        head->next = nullptr;
        return newHead;
    }
};