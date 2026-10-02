// 虽然能做对，复杂度也一样，但是我用了两次dfs，代码太复杂了，跟最佳答案还是有差距
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
    int distributeCoins(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ans = 0;
        if(root->left) {
            pair<int, int> left = getSum(root->left);
            root->left->val += (left.first - left.second);
            root->val -= (left.first - left.second);
            ans += abs(left.first - left.second) + distributeCoins(root->left);
        }
        if (root->right) {
            pair<int, int> right = getSum(root->right);
            root->right->val += (right.first - right.second);
            root->val -= (right.first - right.second);
            ans += abs(right.first - right.second) + distributeCoins(root->right);
        }
        return ans;
    }

    pair<int, int> getSum(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }
        int node = 1;
        int val = root->val;
        pair<int, int> left = getSum(root->left);
        node += left.first;
        val += left.second;
        pair<int, int> right = getSum(root->right);
        node += right.first;
        val += right.second;
        return {node, val};
    }
};

// 最佳答案简洁很多，只需要一次递归调用，返回子树到当前边需要的次数，然后正负值都需要搬运一次，这样问题就解决了
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
    int solve(TreeNode* root, int& ans) {
        if(!root) return 0;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        ans += abs(left) + abs(right);
        return root->val + left +right - 1;
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};