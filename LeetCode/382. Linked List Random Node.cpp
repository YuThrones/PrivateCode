// 没啥好说的，开始遍历一边记录长度，然后随机下表找就完事

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
    int size = 0;
    ListNode* root;
    Solution(ListNode* head) {
        size = 0;
        root = head;
        while(head != nullptr) {
            ++size;
            head = head->next;
        }
    }
    
    int getRandom() {
        int index = rand() % size;
        ListNode* head = root;
        while(index > 0) {
            --index;
            head = head->next;
        }
        return head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */