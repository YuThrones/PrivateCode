// 这道题不用额外空间的话，需要注意遍历顺序，中序遍历保证了处理到当前节点时更小的一定处理完了，这是能一次遍历得出结果的前提
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
    vector<int> findMode(TreeNode* root) {
        map<int, int> record;
        handle(root, record);
        int res = 0;
        for (auto it: record) {
            res = max(res, it.second);
        }
        vector<int> resVec;
        for (auto it: record) {
            if (res == it.second) {
                resVec.push_back(it.first);
            }
        }
        return resVec;
    }

    void handle(TreeNode* root, map<int, int>& record) {
        if (!root) return;
        record[root->val]++;
        handle(root->left, record);
        handle(root->right, record);
    }
};

class Solution {
public:
    std::vector<int> findMode(TreeNode* root) {
        in_order_traversal(root);
        return modes;
    }
private:
    int current_val = 0;
    int current_count = 0;
    int max_count = 0;
    std::vector<int> modes;

    void in_order_traversal(TreeNode* node) {
        if (!node) return;
        
        in_order_traversal(node->left);
        
        current_count = (node->val == current_val) ? current_count + 1 : 1;
        if (current_count == max_count) {
            modes.push_back(node->val);
        } else if (current_count > max_count) {
            max_count = current_count;
            modes = { node->val };
        }
        current_val = node->val;

        in_order_traversal(node->right);
    }
};