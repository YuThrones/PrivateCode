// 第一反应是最简单的递归统计，但是速度比最佳答案慢
// 看了下最佳答案，是在递归思路上做了优化，利用完全二叉树的特性，对比左边界和右边界高度，如果一致可以直接2 ** level -1 算出数量
// 不一致再递归，可以减掉一部分满二叉树的计算
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
        if (!root) {
            return 0;
        }
        int left_height = leftHeight(root);
        int right_height = rightHeight(root);
        if (left_height == right_height) {
            return (1 << left_height) - 1;
        }
        int left_res = countNodes(root->left);
        int right_res = countNodes(root->right);
        return left_res + right_res + 1;
    }
    
    int leftHeight(TreeNode* root) {
        int count = 0;
        while(root) {
            ++count;
            root = root->left;
        }
        return count;
    }
    
    int rightHeight(TreeNode* root) {
        int count = 0;
        while(root) {
            ++count;
            root = root->right;
        }
        return count;
    }
};