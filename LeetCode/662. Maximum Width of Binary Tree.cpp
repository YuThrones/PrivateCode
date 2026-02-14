// 我的方式是用DFS递归，没有BFS看起来简洁，而且多了函数调用栈，还是稍微慢了一点点

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        //TreeNode*, int
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int maxWidth = 1;
        while(!q.empty()) {
            int qsize = q.size();
            int qfrontIndex = q.front().second;
            int qendIndex = q.back().second;
            maxWidth = max(maxWidth, qendIndex - qfrontIndex + 1);
            for (int i = 0; i < qsize; i++) {   // qsize not qsize()
            //for each item, put its children in queue.
                auto[node, index] = q.front();
                q.pop();
                // Normalize index to prevent overflow on deeper levels
                long long normalizedIndex = index - qfrontIndex;

                if (node->left != nullptr)
                //left child will be (2i + 1) of parent i
                    q.push({node->left,  2 * normalizedIndex + 1});
                if (node->right != nullptr)
                //same thing right child of parent i is (2i + 2)
                    q.push({node->right, 2 * normalizedIndex + 2});
            }
        }
        return maxWidth;
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {return 0;}
        vector<pair<int, long long>> record;
        unordered_map<TreeNode*, long long> map;
        root->val = 0;
        handle(record, 1, root, map);

        long long ans = 0;
        for (int i = 0; i < record.size(); ++i) {
            ans = max(ans, record[i].second - record[i].first + 1);
        }
        return ans;
    }

    void handle(vector<pair<int, long long>>& record, int level, TreeNode* root, unordered_map<TreeNode*, long long> map) {
        if (!root) {return;}
        // cout << root->val << " " << level << endl;
        int val = map[root];
        if (record.size() < level) {
            record.push_back({val, val});
        }
        else {
            if (val < record[level - 1].first) {
                record[level - 1].first = val;
            }
            if (val > record[level - 1].second) {
                record[level - 1].second = val;
            }
        }


        if(root->left) {
            // root->left->val = val * 2;
            map[root->left] = (long long)val * 2 + 1;
            handle(record, level + 1, root->left, map);
        }
    
        if(root->right) {
            // root->right->val = val * 2 + 1;
            map[root->right] = (long long)val * 2 + 2;
            handle(record, level + 1, root->right, map);
        }
    }
};