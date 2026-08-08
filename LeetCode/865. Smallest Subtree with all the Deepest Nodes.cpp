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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = 0;
        return cal(root, depth);
    }

    TreeNode* cal(TreeNode* root, int& depth) {
        if(!root) {
            depth = 0;
            return root;
        }
        int leftDepth = 0;
        int rightDepth = 0;
        TreeNode* left = cal(root->left, leftDepth);
        TreeNode* right = cal(root->right, rightDepth);

        if (leftDepth > rightDepth) {
            depth = leftDepth + 1;
            return left;
        }

        if (rightDepth > leftDepth) {
            depth = rightDepth + 1;
            return right;
        }

        depth = leftDepth + 1;
        return root;        
    }
};