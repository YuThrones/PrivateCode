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
        bool findTarget(TreeNode* root, int k) {
            vector<int> nums;
            stack<TreeNode*> st;
            while(root || !st.empty()) {
                if (!root) {
                    root = st.top();
                    st.pop();
                    nums.push_back(root->val);
                    root = root->right;
                }
                else {
                    while(root->left) {
                        st.push(root);
                        root = root->left;
                    }
                    nums.push_back(root->val);
                    root = root->right;
                }
            }
            for (int i = 0; i < nums.size(); ++i) {
                cout << nums[i] << endl;
                int temp = k - nums[i];
                if (std::binary_search(nums.begin() + i + 1, nums.end(), temp)) {
                    return true;
                }
            }
            return false;
        }
    };