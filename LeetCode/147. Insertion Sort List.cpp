// 主要就是考察边界条件，优化下就是要考虑下如果比最后一个大不需要继续插入

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = head;
        head = head->next;
        newHead->next = nullptr;
        ListNode* last = newHead;
        ListNode* temp;
        ListNode* tempLast;
        ListNode* tempNext;
        while(head) {
            temp = newHead;
            tempNext = head->next;
            tempLast = nullptr;
            while(temp && temp->val < head->val) {
                tempLast = temp;
                temp = temp->next;
            }
            if (tempLast) {
                tempLast->next = head;
                head->next = temp;
            }
            else {
                head->next = newHead;
                newHead = head;
            }
            
            head = tempNext;
        }
        
        
        return newHead;
    }
};