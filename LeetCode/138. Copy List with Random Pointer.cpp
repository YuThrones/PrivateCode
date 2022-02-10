// 空间复杂度为O(1)的解法，代价是要遍历三遍，使用原链表节点的random指针暂时存储copy节点，然后使用copy节点的next指针来存储源节点的random
// 第二次遍历时把指针的random节点都设置好，第三次还原原节点的random指针，并且把copy节点的next指针设置好
// 如果只是解题，两次遍历配合哈希表解决即可

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        {
            return head;
        }
        Node* cur1 = head;
        Node* cur2;
        while(cur1 != nullptr)
        {
            cur2 = new Node(cur1->val);
            cur2->next = cur1->random;
            cur1->random = cur2;
            cur1 = cur1->next;
        }
        
        // 第二次遍历把copynode的random设置好
        cur1 = head;
        Node* ans = head->random;
        while(cur1 != nullptr)
        {
            cur2 = cur1->random;
            if (cur2->next)
            {
                cur2->random = cur2->next->random;
            }
            cur1 = cur1->next;
        }
        
        // 第三次遍历设置好copynode的next并复原原本list的random
        cur1 = head;
        Node* pre = new Node(0);
        Node* head2 = pre;
        while(cur1 != nullptr)
        {
            cur2 = cur1->random;
            pre->next = cur2;
            pre = pre->next;
            cur1->random = cur2->next;
            cur1 = cur1->next;
        }
        pre->next = nullptr;
        delete head2;
        
        return ans;
    }
};