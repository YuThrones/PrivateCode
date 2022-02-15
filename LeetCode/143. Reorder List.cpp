// 我的思路是先把列表用快慢指针法两分，然后把后半段倒序，然后两端合并，复杂度是O(n)，看了下最快解法，思路是一样的，拷贝提交后发现基本没什么差距
void PrintList(ListNode* head) {
    cout << "PrintList" << endl;
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        // 二分求出中点先
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        
        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(slow);
        ListNode* temp;
        
        // PrintList(cur1);
        // PrintList(cur2);
        // 合并两个列表
        while(cur1->next != slow) {
            temp = cur2;
            cur2 = cur2->next;
            temp->next = cur1->next;
            cur1->next = temp;
            cur1 = temp->next;
        }
        cur1->next = cur2;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode* newHead = NULL;
        // head = head->next;
        // newHead->next = NULL;
        ListNode* temp = NULL;
        while(head) {
            temp = head;
            head = head->next;
            temp->next = newHead;
            newHead = temp;
        }
        return newHead;
    }
};