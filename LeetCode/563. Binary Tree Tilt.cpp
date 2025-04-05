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
        int findTilt(TreeNode* root) {
            pair<int, int> res = dfs(root);
            return res.second;
        }
    
        pair<int, int> dfs(TreeNode* root) {
            if (!root)    {return make_pair(0, 0);}
            pair<int, int> left = dfs(root->left);
            pair<int, int> right = dfs(root->right);
            return make_pair(left.first + right.first + root->val, left.second + right.second + abs(left.first - right.first));
        }
    };