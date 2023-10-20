// 这道题，一种有四种情况要处理：
// 1. 删除节点没有子节点，直接删除返回空指针
// 2. 删除节点只有左节点，直接返回左指针
// 3. 删除节点只有右节点，直接返回右指针
// 4. 删除节点左右节点都在，可以找到左节点的最右节点或者右节点的最左节点，挪到要删除的节点的位置替换掉当前节点。
// 需要注意这里要处理的细节比较多，需要分类讨论，比如寻找右节点最左节点，如果删除节点的右节点本身没有左节点，那么只需要把右节点提上来替换删除节点，右节点的左节点设为原本删除节点的左节点即可
// 如果最左节点不是删除节点的右节点，那么提上来之后，要注意处理最左节点父节点的左节点，设为最左节点的右节点，避免漏处理

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        TreeNode* temp = nullptr;
        if (root->left && root->right) {
            TreeNode* prev = root;
            temp = root->right;
            while(temp && temp->left) {
                prev = temp;
                temp = temp->left;
            }
            if (temp == root->right) {
                temp->left = root->left;
            }
            else {
                prev->left = temp->right;
                temp->left = root->left;
                temp->right = root->right;
            }
            return temp;
        }
        else if (root->left) {
            return root->left;
        }
        else if (root->right) {
            return root->right;
        }
        return temp;
    }
};