最佳答案使用一个类变量和一个返回值，省下了两个引用传入，而且逻辑简洁很多

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
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxLen;
    }

private:
    int maxLen = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftPath = (node->left && node->left->val == node->val) ? left + 1 : 0;
        int rightPath = (node->right && node->right->val == node->val) ? right + 1 : 0;

        maxLen = max(maxLen, leftPath + rightPath);

        return max(leftPath, rightPath);
    }
};

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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {return 0;}
        int ans = 0;
        int depthToRoot = 0;
        cal(root, ans, depthToRoot);
        return ans - 1;
    }

    void cal(TreeNode* root, int& ans, int& depthToRoot) {
        // cout << "start " << root->val << " " << ans << " " << depthToRoot << endl;
        if(!root) {
            ans = 0;
            depthToRoot = 0;
            return;
        }
        depthToRoot = 1;
        ans = 1;
        int path = 1;
        if (root->left) {
            int tempAns = 0;
            int tempDepth = 0;
            cal(root->left, tempAns, tempDepth);
            if (root->left->val == root->val) {
                depthToRoot = max(depthToRoot, 1 + tempDepth);
                path += tempDepth;
            }
            ans = max(ans, tempAns);
        }
        if (root->right) {
            int tempAns = 0;
            int tempDepth = 0;
            cal(root->right, tempAns, tempDepth);
            if (root->right->val == root->val) {
                depthToRoot = max(depthToRoot, 1 + tempDepth);
                path += tempDepth;
            }
            ans = max(ans, tempAns);
        }
        ans = max(ans, path);
        // cout << "end " << root->val << " " << ans << " " << depthToRoot << endl;
    }
};