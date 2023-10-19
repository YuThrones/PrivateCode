// 这题的思路是仿照加法，应该从后往前加，所以需要逆序节点，很自然的想到了使用栈，然后再用结果生成答案

#include <stack>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        while(l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        stack<int> res;
        while((!st1.empty() && !st2.empty()) || carry) {
            int n1 = 0;
            if (!st1.empty()) {
                n1 = st1.top();
                st1.pop();
            }
            int n2 = 0;
            if (!st2.empty()) {
                n2 = st2.top();
                st2.pop();
            }
            int sum = n1 + n2 + carry;
            res.push(sum % 10);
            carry = sum / 10;
        }
        while(!st1.empty()) {
            res.push(st1.top());
            st1.pop();
        }

        while(!st2.empty()) {
            res.push(st2.top());
            st2.pop();
        }

        if (carry) res.push(carry);
        ListNode* root = nullptr;
        ListNode* last = nullptr;
        while(!res.empty()) {
            int n = res.top();
            res.pop();
            ListNode* temp = new ListNode(n);
            if (!root) root = temp;
            if (last) last->next = temp;
            last = temp;
        }
        return root;
    }
};

int main() {
    ListNode* l1 = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    Solution sol;
    ListNode* root = sol.addTwoNumbers(l1, l2);

}