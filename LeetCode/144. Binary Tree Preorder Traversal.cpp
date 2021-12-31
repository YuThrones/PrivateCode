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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>* res = new vector<int>();
        process(res, root);
        return *res;
    }

    void process(vector<int>* res, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        res->push_back(root->val);
        process(res, root->left);
        process(res, root->right);
        return;
    }
};