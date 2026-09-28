// 核心就是用根节点在前后的位置，锚定左子树，剩下的就是右子树，不过这代码还可以再优化

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int preS = 0;
        int preE = n - 1;
        int postS = 0;
        int postE = n - 1;
        return cal(preorder, postorder, preS, preE, postS, postE);
    }

    TreeNode* cal(vector<int>& preorder, vector<int>& postorder,
        int preS, int preE, int postS, int postE) {
        if(preS > preE) {
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        root->val = preorder[preS];
        if (preS == preE) {
            return root;
        }
        int left = preS + 1;
        int leftNum = 0;
        int i = postS;
        for(i = postS; i < postE; ++i) {
            if(preorder[left] == postorder[i]) {
                leftNum = i - postS + 1;
                root->left = cal(preorder, postorder, 
                left, left + leftNum - 1, postS, i);
                break;
            }
        }
        int right = left + leftNum;
        if(right <= preE) {
            root->right = cal(preorder, postorder, 
                right, preE, i + 1, postE - 1);
        }
        return root;
    }
};