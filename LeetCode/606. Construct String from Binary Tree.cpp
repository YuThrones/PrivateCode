// 唯一需要注意的就是提高字符串拼接效率，只传入一个string比递归调用一直拿子string效率高很多

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
    string tree2str(TreeNode* root) {
        string s;
        handle(s, root);
        return s;
    }

    void handle(string& s, TreeNode* root) {
        if(!root) {
            return;
        }
        s += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return;
        }
        s.push_back('(');
        if (root->left) {
            handle(s, root->left);
        }
        s.push_back(')');
        if(root->right) {
            s.push_back('(');
            handle(s, root->right);
            s.push_back(')');
        }
    }
};