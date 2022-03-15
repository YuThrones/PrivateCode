// mirros遍历
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
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

vector<int> PreOrder(TreeNode* head) {
    stack<TreeNode*> st;
    vector<int> res;
    if (!head) {
        return res;
    }
    // cout << "PrePrint" << endl;
    // st.push(head);
    while(!st.empty() || head) {
        // TreeNode* temp = st.top();
        // st.pop();
        // cout << temp->value << " ";
        // if (temp->right) {
        //     st.push(temp->right);
        // }

        // if (temp->left) {
        //     st.push(temp->left);
        // }
        if (head) {
            res.push_back(head->value);
            st.push(head);
            head = head->left;
        }
        while(!st.empty() && !head) {
            if (st.top()->right) {
                head = st.top()->right;
            }
            st.pop();
        }
    }
    // cout << endl;
    return res;
}


vector<int> InOrder(TreeNode* head) {
    vector<int> res;
    if (!head) {
        return res;
    }
    // cout << "InOrder" << endl;
    stack<TreeNode*> st;
    while (!st.empty() || head)
    {
        if (head) {
            if (head->left) {
                st.push(head);
                head = head->left;
            }
            else {
                // cout << head->value << " ";
                res.push_back(head->value);
                head = head->right;
            }
        }
        else {
            head = st.top();
            st.pop();
            // cout << head->value << " ";
            res.push_back(head->value);
            head = head->right;
        }
    }
    return res;
}


vector<int> PostOrder(TreeNode* head) {
    stack<TreeNode*> st;
    stack<TreeNode*> st2;
    vector<int> res;
    if (!head) {
        return res;
    }
    while(!st.empty() || head) {
        if (head) {
            // res.push_back(head->value);
            st2.push(head);
            st.push(head);
            head = head->right;
        }
        while(!st.empty() && !head) {
            if (st.top()->left) {
                head = st.top()->left;
            }
            st.pop();
        }
    }
    while(!st2.empty()) {
        res.push_back(st2.top()->value);
        st2.pop();
    }
    return res;
}

void PrintVector(vector<int> v) {
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    int count = 10;
    TreeNode* head = GenFullTree(count);
    PrintVector(PreOrder(head));
    PrintVector(InOrder(head));
    PrintVector(PostOrder(head));
    return 0;
}
