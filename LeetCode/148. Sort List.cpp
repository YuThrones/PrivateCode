#include<iostream>
#include<random>
#include<time.h>
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
    ListNode* sortList(ListNode* head) {
        // cout <<"sort"<<endl;
        // Print(head);
        if (head == NULL || head->next == NULL) {
            return head;
        }        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        ListNode* res = Merge(left, right);
        return res;
    }
    
    ListNode* Merge(ListNode* x, ListNode* y) {
        if (x == NULL && y == NULL) {
            return NULL;
        }
        // cout << "merge" << endl;
        // Print(x);
        // Print(y);
        
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode* choose = NULL;
        while (x != NULL || y != NULL) {
            if (x == NULL) {
                cur->next = y;
                break;
            }
            else if (y == NULL) {
                cur->next = x;
                break;
            }
            else if (x->val < y->val) {
                choose = x;
                x = x->next;
            }
            else {
                choose = y;
                y = y->next;
            }
            cur->next = choose;
            cur = cur->next;
        }
        
        return head->next;
    }
    
    void Print(ListNode* head) {
        ListNode* cur = head;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

ListNode* GenRandomList(int num) {
    ListNode* head = NULL;
    ListNode* cur = NULL;
    while (num > 0)
    {
        ListNode* temp = new ListNode(rand() % 100 - rand() % 100);
        if (head == NULL) {
            head = temp;
            cur = temp;
        }
        else {
            cur->next = temp;
            cur = cur->next;
        }
        --num;
    }
    
    return head;
}

int main() {
    Solution s = Solution();
    srand(time(NULL));
    ListNode* head = GenRandomList(1000);
    // s.Print(head);
    double t1 = clock();
    ListNode* res = s.sortList(head);
    double t2 = clock();
    cout << "cost time " << (t2 - t1) / CLOCKS_PER_SEC << endl;
    // s.Print(res);
    return 0;
}