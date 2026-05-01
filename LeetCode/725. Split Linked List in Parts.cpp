// 自己写的也是对的，不过AI优化一下之后可读性强很多

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // 1. 统计链表总长度（命名优化）
        int total = 0;
        ListNode* cur = head;
        while (cur) {
            total++;
            cur = cur->next;
        }

        // 2. 提前计算基础长度和余数（消除重复计算）
        int base = total / k;
        int rem = total % k;
        vector<ListNode*> ans;
        cur = head;

        // 3. 循环分割k次（直接循环k次，替代原while+补空，更简洁）
        for (int i = 0; i < k; ++i) {
            ans.push_back(cur);
            // 当前段的长度：前rem段+1
            int len = base + (i < rem ? 1 : 0);
            
            // 移动len-1步，找到尾节点（删除冗余num变量）
            for (int j = 0; j < len - 1; ++j) {
                cur = cur->next;
            }

            // 断链（空指针时不操作）
            if (cur) {
                ListNode* next = cur->next;
                cur->next = nullptr;
                cur = next;
            }
        }
        return ans;
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            ++cnt;
            temp = temp->next;
        }
        int piece = cnt / k;
        vector<ListNode*> ans;
        temp = head;
        while(temp != nullptr) {
            ans.push_back(temp);
            int num = 0;
            ListNode* last = temp;
            int len = (ans.size() <= (cnt % k)) ? piece + 1 : piece;
            while(temp != nullptr && num < len) {
                last = temp;
                temp = temp->next;
                ++num;
            }
            last->next = nullptr;
        }
        while(ans.size() < k) {
            ans.push_back(nullptr);
        }
        return ans;
    }
};