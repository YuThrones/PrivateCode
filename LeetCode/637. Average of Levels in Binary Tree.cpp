// 一开始自己的实现是把每一层的和收集起来，可以ac，不过看了下最佳答案用队列来做，更加优雅一点，速度是一样的

#include<vector>
#include<queue>
using namespace std;

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
    vector<pair<double, double>> data;

    vector<double> averageOfLevels(TreeNode* root) {
        data.clear();
        handle(root, 0);
        vector<double> ans;
        for (int i = 0; i < data.size(); ++i) {
            ans.push_back(data[i].second / data[i].first);
        }
        return ans;
    }

    void handle(TreeNode* root, int level) {
        if (!root) return;
        if (data.size() == level) {
            data.push_back({0, 0});
        }
        data[level].first += 1;
        data[level].second += root->val;
        handle(root->left, level + 1);
        handle(root->right, level + 1);
    }

};


class Solution {
public:

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            double sum = 0;
            int num = q.size();
            for(int i = 0; i < num; ++i) {
                root = q.front();
                q.pop();
                sum += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.push_back(sum / num);
        }

        return ans;
    }

};