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
    int countNodes(TreeNode* root) {
        return cal(root, -1, -1);
    }
    
    int cal(TreeNode* root, int l, int r) {
        if (!root) return 0;
        
        if (l == -1) {
            l = maxSideHeight(root, true);
        }
        
        if (r == -1) {
            r = maxSideHeight(root, false);
        }
        
        if (l == r) {
            return pow(2, l) - 1;
        }
        else {
            return cal(root->left, l - 1, -1) + cal(root->right, -1, r - 1) + 1;
        }
    }
    
    int maxSideHeight(TreeNode* root, bool isLeft) {
        int count = 0;
        while(root) {
            ++count;
            if (isLeft) root = root->left;
            else root = root->right;
        }
        return count;
    }
};