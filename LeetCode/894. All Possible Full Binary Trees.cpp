// 其实可以不用clone，速度更快，这道题里面这么做没有影响

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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp;
        dp.push_back({nullptr});
        TreeNode* node = new TreeNode();
        dp.push_back({node});
        for(int i = 2; i <= n; ++i) {
            dp.push_back({});
            for(int j = 1; j < i; ++j) {
                int k = i - 1 - j;
                if(k < 1) {break;}
                for(auto left : dp[j]) {
                    for(auto right: dp[k]) {
                        node = new TreeNode();
                        node->left = clone(left);
                        node->right = clone(right);
                        dp[i].push_back(node);
                    }
                }
            }
        }
        return dp[n];
    }

    TreeNode* clone(TreeNode* root) {
        if (!root) {return nullptr;}
        TreeNode* newRoot = new TreeNode();
        newRoot->left = clone(root->left);
        newRoot->right = clone(root->right);
        return newRoot;
    }
};