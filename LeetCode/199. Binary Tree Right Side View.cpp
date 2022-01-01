// 树形DP的思路，从左右两边各自拿到右边界，然后用右子树的右边界覆盖左子树的，再在头部插入自己
// 更快的解法是用bfs的思路来做的，但是我感觉时间复杂度应该是一致的，可能在空间复杂度上有所优化，复制之后尝试提交，跟我想象的差不多

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
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> res = vector<int>();
        if (!root) {
            return vector<int>();
        }
        vector<int> left_res = rightSideView(root->left);
        vector<int> right_res = rightSideView(root->right);

        for (int i = right_res.size(); i < left_res.size(); ++i) {
            right_res.push_back(left_res[i]);
        }

        right_res.insert(right_res.begin(), root->val);
        return right_res;
    }
};