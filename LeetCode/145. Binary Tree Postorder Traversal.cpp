// 看起来引用比直接传指针要快，有点不科学的样子
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>* res = new vector<int>();
        process(res, root);
        return *res;
    }

    void process(vector<int>* res, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        process(res, root->left);
        process(res, root->right);
        res->push_back(root->val);
        return;
    }
};