// mirros遍历
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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

vector<int> GetTreeValues(TreeNode* head) {
    vector<int> res;
    queue<TreeNode*> q = queue<TreeNode*>();
    q.push(head);
    TreeNode *cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        // cout << cur->value << endl;
        res.push_back(cur->value);
        if (cur->left != NULL) {
            q.push(cur->left);
        }
        if (cur->right != NULL) {
            q.push(cur->right);
        }
    }
    return res;
}


void SwitchTree1(TreeNode* head, int index1, int index2) {
    TreeNode* newHead = head;
    queue<TreeNode*> q;
    q.push(head);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->value == index1) {
            temp->value = index2;
        }
        else if (temp->value == index2)
        {
            temp->value = index1;
        }

        if (temp->left) {
            q.push(temp->left);
        }
        
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

TreeNode* SwitchTree2(TreeNode* head, int index1, int index2) {
    TreeNode* cur = head;
    TreeNode* pre = new TreeNode();
    pre->left = head;
    TreeNode* newHead = pre;
    TreeNode *node1, *node2, *pre1, *pre2;
    TreeNode* temp;
    TreeNode* tempL;
    TreeNode* tempR;
    
    stack<TreeNode*> st;

    // 先找到两个节点以及他们的父节点
    while(cur || !st.empty()) {
        if (cur) {
            if (cur->value == index1) {
                node1 = cur;
                pre1 = pre;
            }
            else if (cur->value == index2)
            {
                node2 = cur;
                pre2 = pre;
            }
            st.push(cur);
            pre = cur;
            cur = cur->left;
        }
        else {
            while(!st.empty()) {
                cur = st.top();
                st.pop();
                if (cur->right) {
                    break;
                }
            }

            if (cur->right) {
                pre = cur;
                cur = cur->right;
            }
            else {
                cur = nullptr;
            }
        }
    }

    
    if (pre2 == node1) {
        // node2的父节点是node1，将两者交换，用node1的父节点是node2的方式处理
        temp = node1;
        node1 = node2;
        node2 = temp;
        temp = pre1;
        pre1 = pre2;
        pre2 = temp;
    }

    if (pre1 == node2) {
        // node1的父节点是node2
        tempL = node1->left;
        tempR = node1->right;

        pre2->left == node2 ? pre2->left = node1 : pre2->right = node1;
        if (node2->left == node1) {
            node1->left = node2;
            node1->right = node2->right;
        }
        else {
            node1->right = node2;
            node1->left = node2->left;
        }
        node2->left = tempL;
        node2->right = tempR;
    }
    else {
        // 两者不存在连接关系，直接换节点
        tempL = node1->left;
        tempR = node1->right;
        node1->left = node2->left;
        node1->right = node2->right;

        if (pre1 == pre2) {
            temp = pre1->left;
            pre1->left = pre1->right;
            pre1->right = temp;
        }
        else{
            pre1->left == node1 ? pre1->left = node2 : pre1->right = node2;
            pre2->left == node2 ? pre2->left = node1 : pre2->right = node1;
        }
        
        node2->left = tempL;
        node2->right = tempR;
    }

    return newHead->left;
}


int main() {
    int testTimes = 10000;
    int count = 100;

    for (int i = 0; i < testTimes; ++i) {
        TreeNode* head = GenFullTree(count);
        // Print(head);
        TreeNode* newHead = CopyTree(head);
        // Print(newHead);
        int index1 = rand() % count + 1;
        int index2 = rand() % count + 1;
        if (index1 == index2) {
            index2 = index1 - 1;
        }
        if (index2 == 0) {
            index2 = count;
        }

        // TODO
        // index1 = 4;
        // index2 = 5;

        // cout << index1 << " " << index2 << endl;
        SwitchTree1(head, index1, index2);
        vector<int> res1 = GetTreeValues(head);
        newHead = SwitchTree2(newHead, index1, index2);
        vector<int> res2 = GetTreeValues(newHead);

        // cout << "Res1:" << endl;
        // for(int i = 0; i < res1.size(); ++i) {
        //     cout << res1[i] << " ";
        // }
        // cout << endl;

        // cout << "Res2:" << endl;
        // for(int i = 0; i < res2.size(); ++i) {
        //     cout << res2[i] << " ";
        // }
        // cout << endl;

        for(int i = 0; i < res1.size(); ++i) {
            
            if (res1[i] != res2[i]) {
                cout << "wrong" << endl;
                cout << index1 << " " << index2 << endl;
                Print(head);
                Print(newHead);
                break;
            }
        }
    }

    return 0;
}
