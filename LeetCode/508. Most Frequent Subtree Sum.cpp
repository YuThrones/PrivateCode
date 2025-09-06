// 思路很简单，就是在求子节点和的同时记录下当前子节点和出现的次数，再两次遍历求最大出现次数就好
// 不过最佳答案常数时间不知道为什么更快

class Solution {
public:
    int helper(TreeNode* root, vector<int>& subtreeSum){
        if(!root) return 0;

        int ans = root->val;
        ans += helper(root->left, subtreeSum);
        ans += helper(root->right, subtreeSum);

        subtreeSum.push_back(ans);
        return ans;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};

        vector<int> subtreeSum;
        helper(root, subtreeSum);

        unordered_map<int, int> countMap;
        int maxFreq = 0;

        // Count frequencies
        for(int sum : subtreeSum){
            countMap[sum]++;
            maxFreq = max(maxFreq, countMap[sum]);
        }

        // Collect results with max frequency
        vector<int> res;
        for(auto& [sum, freq] : countMap){
            if(freq == maxFreq){
                res.push_back(sum);
            }
        }

        return res;
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
    unordered_map<int, int> record;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        record.clear();
        cal(root);
        vector<int> ans;
        int maxVal = 0;
        for (auto it : record) {
            maxVal = max(maxVal, it.second);
        }
        for (auto it : record) {
            if (maxVal == it.second) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }

    int cal(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = root->val + cal(root->left) + cal(root->right);
        ++record[sum];
        return sum;
    }
};