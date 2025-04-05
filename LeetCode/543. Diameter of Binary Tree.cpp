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
        int diameterOfBinaryTree(TreeNode* root) {
            return dfs(root).second - 1;
        }
    
        pair<int, int> dfs(TreeNode* root) {
            if (!root) {return make_pair(0, 0);}
            pair<int, int> left = dfs(root->left);
            pair<int, int> right = dfs(root->right);
            int depth = max(left.first, right.first) + 1;
            int path = max(max(left.second, right.second), left.first + right.first + 1);
            return make_pair(depth, path);
        }
    };