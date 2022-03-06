// mirros遍历
#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
        TreeNode* left;
        TreeNode* right;
        int value;
        TreeNode() {}
        TreeNode(int value, TreeNode* left, TreeNode* right) {
            this->value = value;
            this->left = left;
            this->right = right;
        }
};


TreeNode* CopyTree(TreeNode* head) {
    if (!head) {
        return nullptr;
    }
    TreeNode* newHead;
    newHead = new TreeNode(head->value, CopyTree(head->left), CopyTree(head->right));
    return newHead;
}


TreeNode* GenFullTree(int count) {
    TreeNode* head = new TreeNode(1, NULL, NULL);
    queue<TreeNode*> q = queue<TreeNode*>();
    q.push(head);
    int i = 1;
    TreeNode* cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        cur->left = new TreeNode(++i, NULL, NULL);
        q.push(cur->left);
        if (i >= count) {
            break;
        }
        cur->right = new TreeNode(++i, NULL, NULL);
        q.push(cur->right);
        if (i >= count) {
            break;
        }
    }
    return head;
}

void Print(TreeNode* head) {
    queue<TreeNode*> q = queue<TreeNode*>();
    q.push(head);
    TreeNode *cur;
    cout << "print tree start" << endl;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur->value << endl;
        if (cur->left != NULL) {
            q.push(cur->left);
        }
        if (cur->right != NULL) {
            q.push(cur->right);
        }
    }
    cout << "print tree end" << endl;
}

int main() {
    TreeNode* head = GenFullTree(10);
    Print(head);
    TreeNode* newHead = CopyTree(head);
    Print(newHead);
    return 0;
}

inorder(node) {
    if (node == nullptr) {
        return node;
    }
    inorder(node->left);
    dosomething()
    inorder(node->right);
}

queue q;
while(cur) {

}

stack s;
while(cur && !s.empty()) {
    if (!cur) {
        cur = s.top();
        s.pop();
        print cur.val;
        cur = cur->right;
    }
    else {
        s.push(cur);
        cur = cur->left;
    }
}