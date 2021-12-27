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

void ReversePrint(TreeNode *head) {
    if (head == NULL) {
        return;
    }
    TreeNode *last = NULL;
    TreeNode *next = NULL;
    TreeNode *cur = head;
    while (cur != NULL)
    {
        next = cur->right;
        cur->right = last;
        last = cur;
        cur = next;
    }
    cur = last;
    last = NULL;
    next = NULL;
    while (cur != NULL)
    {
        cout << cur->value << endl;
        next = cur->right;
        cur->right = last;
        last = cur;
        cur = next;
    }
    
}

void MirrosTraverse(TreeNode* head) {
    if (head == NULL) {
        return;
    }
    TreeNode* cur = head;
    TreeNode* maxRight;
    while(cur != NULL) {
        if (cur->left != NULL)
        {
            maxRight = cur->left;
            while(maxRight->right != NULL && maxRight->right != cur) {
                maxRight = maxRight->right;
            }
            if (maxRight->right == NULL) {
                // 第一次访问有左子节点的根节点
                maxRight->right = cur;
                cur = cur->left;
                continue;
            }
            else {
                // 第二次访问有左子节点的根节点
                maxRight->right = NULL;
            }
            
        }
        cur = cur->right;
    }
}

void PreOrderTraverse(TreeNode* head) {
    cout << "PreOrderTraverse start" << endl;
    if (head == NULL) {
        return;
    }
    TreeNode* cur = head;
    TreeNode* maxRight;
    while(cur != NULL) {
        if (cur->left != NULL)
        {
            maxRight = cur->left;
            while(maxRight->right != NULL && maxRight->right != cur) {
                maxRight = maxRight->right;
            }
            if (maxRight->right == NULL) {
                // 第一次访问有左子节点的根节点
                cout << cur->value << endl;
                maxRight->right = cur;
                cur = cur->left;
                continue;
            }
            else {
                // 第二次访问有左子节点的根节点
                maxRight->right = NULL;
            }
        }
        else {
            cout << cur->value << endl;
        }
        cur = cur->right;
    }
    cout << "PreOrderTraverse end" << endl;
}

void InOrderTraverse(TreeNode* head) {
    cout << "InOrderTraverse start" << endl;
    if (head == NULL) {
        return;
    }
    TreeNode* cur = head;
    TreeNode* maxRight;
    while(cur != NULL) {
        if (cur->left != NULL)
        {
            maxRight = cur->left;
            while(maxRight->right != NULL && maxRight->right != cur) {
                maxRight = maxRight->right;
            }
            if (maxRight->right == NULL) {
                // 第一次访问有左子节点的根节点
                maxRight->right = cur;
                cur = cur->left;
                continue;
            }
            else {
                // 第二次访问有左子节点的根节点
                maxRight->right = NULL;
            }
            
        }
        cout << cur->value << endl;
        cur = cur->right;
    }
    cout << "InOrderTraverse end" << endl;
}

void PostOrderTraverse(TreeNode* head) {
    cout << "PostOrderTraverse start" << endl;
    if (head == NULL) {
        return;
    }
    TreeNode* cur = head;
    TreeNode* maxRight;
    while(cur != NULL) {
        if (cur->left != NULL)
        {
            maxRight = cur->left;
            while(maxRight->right != NULL && maxRight->right != cur) {
                maxRight = maxRight->right;
            }
            if (maxRight->right == NULL) {
                // 第一次访问有左子节点的根节点
                maxRight->right = cur;
                cur = cur->left;
                continue;
            }
            else {
                // 第二次访问有左子节点的根节点
                maxRight->right = NULL;
                ReversePrint(cur->left);
            }
        }
        cur = cur->right;
    }
    ReversePrint(head);
    cout << "PostOrderTraverse end" << endl;
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
    PostOrderTraverse(head);
    return 0;
}