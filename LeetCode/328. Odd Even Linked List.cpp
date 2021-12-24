// 遍历一次链表，并且把偶数的index都放到一个新链表，最后两个链表连起来即可
// 看了下最快的解法，他没有用一个index记录奇偶性，而是用两个指针分别指向第一个和第二个节点，然后交替指向奇偶链表的下一个节点，确实更加巧妙
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* evenHead = new ListNode();
        ListNode* cur = evenHead;
        ListNode* curOdd = head;
        ListNode* last = head;
        int index = 0;
        while(curOdd != NULL) {
            if (index % 2 == 1) {
                cur->next = curOdd;
                last->next = curOdd->next;
                curOdd = curOdd->next;
                cur = cur->next;
            }
            else {
                last = curOdd;
                curOdd = curOdd->next;
            }
            ++index;
        }
        cur->next = NULL;
        last->next = evenHead->next;
        return head;
    }
};


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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        
        ListNode* odd = head, *_odd = head, *even = head->next, *_even = head->next;
        
        while (even != nullptr)
        {
            if (odd == nullptr) break;
            
            odd->next = even->next;
            even->next = odd->next == nullptr ? nullptr : odd->next->next;
            odd = odd->next;
            even=even->next;
        }
        
        odd = _odd;
        ListNode* prev = nullptr;
        while (odd != nullptr)
        {
            prev = odd;
            odd = odd->next;
        }
        
        prev->next = _even;
        
        return _odd;
    }
};