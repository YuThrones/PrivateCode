// 这道题很自然的想到用一个递归解决，但是要更快还是要用递推，消除函数开销，不过基本在一个量级

#include <vector>
#include <stack>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    // Node* handle(Node* head) {
    //     if (!head) return nullptr;
    //     Node* oriNext;
    //     Node* curTail;
    //     Node* tail;
    //     while(head) {
    //         oriNext = head->next;
    //         if (head->child) {
    //             tail = handle(head->child);
    //             tail->next = head->next;

    //             if (head->next) {
    //                 head->next->prev = tail;
    //             }
    //             curTail = tail;

    //             head->next = head->child;
    //             head->child->prev = head;
    //             head->child = nullptr;
    //         }
    //         else {
    //             curTail = head;
    //         }
    //         head = oriNext;
    //     }
    //     return curTail;
    // }

    // Node* flatten(Node* head) {
    //     handle(head);
    //     return head;
    // }

    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* oriHead = head;
        while(head) {
            if (head->child) {
                if (head->next) {
                    st.push(head->next);
                }
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                head = head->next;
            }
            else if(!head->next && !st.empty()) {
                Node* next = st.top();
                st.pop();
                head->next = next;
                next->prev = head;
                head = next;
            }
            else {
                head = head->next;
            }

        }
        return oriHead;
    }
};


int main() {

    return 0;
}