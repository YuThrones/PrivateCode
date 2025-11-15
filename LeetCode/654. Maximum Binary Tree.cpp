直接用递归就可以解决，但是不是最快答案，递归做出来之后看了下最快答案，通过堆栈只遍历一次nums数组，
节省了每次递归遍历nums的开销，通过维持一个单调递减栈，动态调整左右子节点，保证父子节点关系正确。

TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    std::stack<std::unique_ptr<TreeNode>> st;  // 栈存智能指针，自动管理内存（避免泄漏）
    
    for (int num : nums) {
        auto node = std::make_unique<TreeNode>(num);  // 创建当前值的节点（所有权归unique_ptr）

        // 步骤1：栈中所有比当前节点小的，都作为当前节点的左子树
        while (!st.empty() && st.top()->val < num) {
            // release()：释放智能指针的所有权，返回裸指针（转移给node->left）
            node->left = st.top().release();
            st.pop();  // 弹出已转移所有权的节点
        }

        // 步骤2：栈不为空时，栈顶（比当前大）的右子树 = 当前节点
        if (!st.empty()) {
            // get()：获取智能指针的裸指针（不释放所有权）
            st.top()->right = node.get();
        }

        // 步骤3：将当前节点（转移所有权）压入栈
        st.emplace(std::move(node));  // unique_ptr不可拷贝，只能move
    }

    // 栈底是根节点（数组最大值），释放所有权并返回裸指针
    while (st.size() > 1) {
        st.top().release();  // 释放非根节点的所有权（已挂载到其他节点，无需保留）
        st.pop();
    }
    return st.top().release();  // 返回根节点裸指针（交给调用者管理）
}

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int start, int end) {
        if(start > end) {
            return nullptr;
        }
        TreeNode* res = new TreeNode();
        int maxNum = INT_MIN;
        int index = -1;
        for(int i = start; i <= end; ++i) {
            if(nums[i] > maxNum) {
                maxNum = nums[i];
                index = i;
            }
        }
        res->val = maxNum;
        res->left = build(nums, start, index - 1);
        res->right = build(nums, index + 1, end);
        return res;
    }
};