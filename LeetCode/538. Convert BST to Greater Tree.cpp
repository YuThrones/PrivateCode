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
    TreeNode* convertBST(TreeNode* root) {
        handle(root, 0);
        return root;   
    }

    int handle(TreeNode* root, int ext) {
        if (!root) {
            return 0;
        }
        int rsum = handle(root->right, ext);
        int mid = root->val;
        int lsum = handle(root->left, rsum + mid + ext);
        root->val = root->val + rsum + ext;
        return lsum + rsum + mid;
    }
};