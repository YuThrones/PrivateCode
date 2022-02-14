// 直接一个快慢指针解决问题，要注意都是从第一个节点开始即可
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) {
            return NULL;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast != NULL && fast->next != NULL) {
            if (slow == fast) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast || !fast->next) {
            return NULL;
        }
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};