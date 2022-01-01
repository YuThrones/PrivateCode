// 我的想法是使用栈进行中序遍历，每次把一个节点左边界放到栈中，然后依次弹出，弹出过程中返回并对右节点做同样的事情。
// 看起来比最佳答案慢了很多，但是我看了下代码思路是类似的，他只是提前push了内容，copy之后测试，大概速度有一倍的差距，没有显示的那么大，但是还是得研究下
// 我感觉像是头结点先push了一波偷跑了，暂时不管
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
class BSTIterator {
public:
    TreeNode* cur;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        cur = root;
        st = stack<TreeNode*>();
    }
    
    int next() {
        while(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        int res = cur->val;
        cur = cur->right;
        return res;
    }
    
    bool hasNext() {
        return cur != nullptr || !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */