// 可以直接标准的使用堆解决，所有节点扔最小堆，然后弹出拼接就行
// 看了下最快答案，是使用了两两merge，类似二分的方式来做，会快一半左右，可以借鉴下，不过复杂度呀应该都是O(nlogn)，应该只存在常数上的优势
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
struct cmp{
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq = priority_queue<ListNode*, vector<ListNode*>, cmp>();
        ListNode* head = NULL;
        ListNode* cur = NULL;
        for (int i = 0; i < lists.size(); ++i) {
            head = lists[i];
            while(head != NULL) {
                pq.push(head);
                head = head->next;
            }
        }
        cur = head = new ListNode();
        while(!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
        }
        cur->next = NULL;
        return head->next;
    }
};