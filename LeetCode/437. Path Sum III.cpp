// 这道题不难想到用递归，唯一注意的就是移除，这个数据用long能解决
// 最佳答案的区别是，用类似求最大累加和的方式，记录下从根节点到当前节点某些加和的数目，然后看看用当前节点减去目标，能否找到一个累加和的路径等于这个差值
// 如果可以找到，那么找到的这个值的数量，就是从上面一直到这个节点可以加到目标值的数量

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
    int ans = 0;
    unordered_map<long, int> ma;

    int pathSum(TreeNode* root, int targetSum) {
        ma[0] = 1;
        traverse(root, 0, targetSum);
        return ans;
    }

    void traverse(TreeNode* root, long curSum, long targetSum) {
        if (!root) return;

        curSum += root->val;

        long oldSum = curSum - targetSum; 
        if (ma.contains(oldSum)) ans += ma[oldSum];

        // ans += (ma.contains(oldSum)) ? ma[oldSum] : 0;
        ma[curSum]++;

        traverse(root->left, curSum, targetSum);
        traverse(root->right, curSum, targetSum);

        ma[curSum]--;
    }
};