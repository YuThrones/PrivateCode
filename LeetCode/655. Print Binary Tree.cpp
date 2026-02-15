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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getH(root);
        int m = height;
        int n = (1 << height) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        queue<pair<TreeNode*, int>> q;
        int r = 0;
        q.push({root, n / 2});
        int diff;
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<TreeNode*, int> f = q.front();
                q.pop();
                ans[r][f.second] = to_string(f.first->val);


                if(r < height - 1) {
                    diff = 1 << (height - 2 - r);
                }

                if(f.first->left) {
                    q.push({f.first->left, f.second - diff});
                }
                if(f.first->right) {
                    q.push({f.first->right, f.second + diff});
                }
            }
            ++r;
        }
        return ans;
    }

    int getH(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return max(getH(root->left), getH(root->right)) + 1;
    }
};