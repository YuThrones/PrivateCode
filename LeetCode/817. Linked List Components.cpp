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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> dct;
        for(int n : nums) {
            dct.insert(n);
        }
        int ans = 0;
        bool bFound = false;
        while(head) {
            if (dct.contains(head->val)) {
                if(!bFound) {
                    bFound = true;
                    ++ans;
                }
            }
            else {
                bFound = false;
            }
            head = head->next;
        }
        return ans;
    }
};