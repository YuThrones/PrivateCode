// 这道题一开始没看清楚题意，想岔了，当做无序树来解，事实上要利用有序信息来处理这个问题。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        if (p->val > q->val) {
            return process(root, q->val, p->val);
        }
        return process(root, p->val, q->val);
    }
    
    TreeNode* process(TreeNode* root, int p, int q) {
        int val;
        while(root) {
            val = root->val;
            if (val == p || val == q) {
                return root;
            }
            if (val > q) {
                root = root->left;
            }
            else if (val < p) {
                root = root->right;
            }
            else {
                return root;
            }
        }
        return root;
    }
};

// 一开始理解错写的代码
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        // cout << root->val << endl;
        if (root == p || root == q) {
            return root;
        }
        bool p_left = inTree(root->left, p);
        bool q_left = inTree(root->left, q);
        if (p_left && q_left) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // bool p_right = inTree(root->right, p);
        // bool q_right = inTree(root->right, q);
        if (!p_left && !q_left) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    
    bool inTree(TreeNode* root, TreeNode* find) {
        if (!root) {
            return false;
        }
        if (root == find) {
            return true;
        }
        // cout << "check" << root->val << " " << find->val << endl;
        bool left = inTree(root->left, find);
        bool right = inTree(root->right, find);
        if (left) {
            return left;
        }
        else {
            return right;
        }
    }
};