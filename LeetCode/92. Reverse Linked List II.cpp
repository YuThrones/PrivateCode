// 同样是遍历链表但是边界条件复杂了很多，最好是画链表图理清楚，靠想容易乱
// 看了下最快的解法是用vector做的，这样浪费了额外空间，应该不是题目想要考察的，还是维持这样吧
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !left || !right) {
            return NULL;
        }
        ListNode* last = NULL;
        ListNode* next = NULL;
        ListNode* cur = NULL;
        ListNode* new_head = new ListNode();
        ListNode* left_last = NULL;
        // ListNode* right_next = NULL;
        
        new_head->next = head;
        cur = new_head;
        int index = 0;
        while(index != left) {
            last = cur;
            cur = cur->next;
            ++index;
        }
        left_last = last;
        last = NULL;
        while(index <= right) {
            next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
            ++index;
        }
        left_last->next->next = cur;
        left_last->next = last;
        return new_head->next;
    }
    
};