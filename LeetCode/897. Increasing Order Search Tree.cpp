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
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {return nullptr;}
        pair<TreeNode*, TreeNode*> result = process(root);
        return result.first;
    }

    pair<TreeNode*, TreeNode*> process(TreeNode* root) {
        if (!root) {
            return make_pair(nullptr, nullptr);
        }
        // cout << root->val << endl;
        if (!root->left && !root->right) {
            return make_pair(root, root);
        }

        TreeNode* first = root;
        TreeNode* second = root;
        pair<TreeNode*, TreeNode*> leftResult = process(root->left);
        if (leftResult.first) {
            first = leftResult.first;
            leftResult.second->right = root;
        }
        pair<TreeNode*, TreeNode*> rightResult = process(root->right);
        if(rightResult.first) {
            root->right = rightResult.first;
            second = rightResult.second;
        }
        root->left = nullptr;
        return make_pair(first, second);
    }
};