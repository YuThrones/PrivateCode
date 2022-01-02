// 经典树形DP，左右子树拿之后组合即可
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res = vector<string>();
        if (!root) {
            return res;
        }
        string root_val = to_string(root->val);
        if (!root->left && ! root->right) {
            res.push_back(root_val);
        }
        root_val += "->";
        vector<string> left_res = binaryTreePaths(root->left);
        vector<string> right_res = binaryTreePaths(root->right);
        for (int i = 0; i < left_res.size(); ++i) {
            res.push_back(root_val + left_res[i]);
        }
        for (int i = 0; i < right_res.size(); ++i) {
            res.push_back(root_val + right_res[i]);
        }
        return res;
    }
    
};