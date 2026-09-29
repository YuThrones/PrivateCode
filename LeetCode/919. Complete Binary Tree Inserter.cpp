// 能过，但是慢了点，还是得对树做预处理，把还没满两个节点的都保存到树里面

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* rt;
    CBTInserter(TreeNode* root) {
        rt = root;
    }
    
    int insert(int val) {
        pair<TreeNode*, int> parent = get_parent(rt, 0);
        if (!parent.first->left) {
            parent.first->left =  new TreeNode(val);
        }
        else {
            parent.first->right =  new TreeNode(val);
        }
        return parent.first->val;
    }
    
    TreeNode* get_root() {
        return rt;
    }

    pair<TreeNode*, int> get_parent(TreeNode* root, int depth) {
        if (!root->left || !root->right) {
            return {root, depth};
        }
        pair<TreeNode*, int> left = get_parent(root->left, depth + 1);
        pair<TreeNode*, int> right = get_parent(root->right, depth + 1);
        if (left.second > right.second) {
            return right;
        }
        return left;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

 class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) : root(root) {
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            if (cur->left && cur->right) {
                q.pop();
            } else {
                break;
            }
        }
    }
    
    int insert(int val) {
        TreeNode* parent = q.front();
        TreeNode* node = new TreeNode(val);
        if (!parent->left) {
            parent->left = node;
        } else {
            parent->right = node;
            q.pop();
        }
        q.push(node);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};