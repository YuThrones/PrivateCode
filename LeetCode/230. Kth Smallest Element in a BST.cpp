// 这道题本质上还是中序遍历，不需要想太复杂，把中序遍历打印的行为变成 k-1 并且在k为0的时候返回栈顶即可
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st = stack<TreeNode*>();
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                k -= 1;
                if (k == 0) {
                    return cur->val;
                }
                st.pop();
                cur = cur->right;
            }
        }
        return 0;
    }
};