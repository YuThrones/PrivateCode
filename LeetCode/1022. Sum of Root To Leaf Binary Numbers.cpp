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
    int sumRootToLeaf(TreeNode* root) {
        return cal(root, 0);
    }

    int cal(TreeNode* root, int value) {
        if (!root) {
            return value;
        }
        value = value * 2 + root->val;
        if (!root->left && !root->right) {
            return value;
        }
        int sum = 0;
        if (root->left) {
            sum += cal(root->left, value);
        }
        if (root->right) {
            sum += cal(root->right, value);
        }
        return sum;
    }
};