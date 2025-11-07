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
    bool isCousins(TreeNode* root, int x, int y) {
        auto xd = depth(root, x);
        auto yd = depth(root, y);
        cout << xd.second << " " << yd.second << endl;
        return xd.second != 0 && yd.second != 0 && xd.second == yd.second && xd.first != yd.first;
    }

    pair<TreeNode*, int> depth(TreeNode* root, int val) {
        if(!root) {
            return {nullptr, 0};
        }
        if(root->val == val) {
            return {nullptr, 1};
        }
        auto left = depth(root->left, val);
        if(left.second == 1) {
            left.first = root;
        }
        if(left.second > 0) {
            ++left.second;
            return left;
        }
        auto right = depth(root->right, val);
        if(right.second == 1) {
            right.first = root;
        }
        if (right.second > 0) {
            ++right.second;
            return right;
        }
        return {nullptr, 0};
    }
};