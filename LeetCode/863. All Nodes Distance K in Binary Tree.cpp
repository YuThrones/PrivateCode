/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            if(temp->left) {
                par[temp->left] = temp;
                que.push(temp->left);
            }
            if(temp->right) {
                par[temp->right] = temp;
                que.push(temp->right);
            }
        }
        unordered_set<TreeNode*> us;
        us.insert(target);
        
        int dis = 0;
        vector<TreeNode*> vec;
        vec.push_back(target);
        int i = 0;
        while(dis < k) {
            int n = vec.size();
            while(i < n) {
                TreeNode* temp = vec[i];
                auto parent = par[temp];
                if(parent && !us.contains(parent)) {
                    us.insert(parent);
                    vec.push_back(parent);
                }
                auto left = temp->left;
                if(left && !us.contains(left)) {
                    us.insert(left);
                    vec.push_back(left);
                }
                auto right = temp->right;
                if(right && !us.contains(right)) {
                    us.insert(right);
                    vec.push_back(right);
                }
                ++i;
            }
            ++dis;
        }
        vector<int> ans;
        if (dis == k) {
            while(i < vec.size()) {
                ans.push_back(vec[i]->val);
                ++i;
            }
        }
        return ans;
    }
};