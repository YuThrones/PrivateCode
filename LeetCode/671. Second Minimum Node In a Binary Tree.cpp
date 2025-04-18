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
        int findSecondMinimumValue(TreeNode* root) {
            return handle(root);
        }
    
        int handle(TreeNode* root) {
            if (!root) {return -1;}
            if (!root->left || !root->right) {return -1;}
            if (root->left && root->right) {
                if (root->left->val > root->right->val) {
                    int sub = handle(root->right);
                    if (sub == -1) {return root->left->val;}
                    return min(sub, root->left->val);
                }
                else if (root->right->val > root->left->val) {
                    int sub = handle(root->left);
                    if (sub == -1) {return root->right->val;}
                    return min(sub, root->right->val);
                }
                else {
                    int left = handle(root->left);
                    int right = handle(root->right);
                    if (left == -1) {return right;}
                    if (right == -1) {return left;}
                    return min(left, right);
                }
            }
            return -1;
        }
    };