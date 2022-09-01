// 通过重写unordered_map的哈希函数，写了一个带存储的递归，最佳答案也是递归，但是左右都只有一次调用，直接传两个引用用于存储是否调用本层的答案，避免了复杂度上升
// 我修改下递归，两个一起传上来，效果是一致的，改良后试了下，确实如此


 
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = cal(root);
        return max(ans.first, ans.second);
    }
    
    pair<int, int> cal(TreeNode* root) {
        if (root == nullptr ) return {0, 0};
        
        pair<int, int> ans;
        pair<int, int> ansl = cal(root->left);
        pair<int, int> ansr = cal(root->right);
        ans.first = root->val + ansl.second + ansr.second;
        ans.second = max(ansl.first, ansl.second) + max(ansr.first, ansr.second);
        return ans;
    }
    
    
};

#include<unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct pairHash {
    size_t operator()(const pair<TreeNode*, bool>& p) const {
        hash<TreeNode*> hash_node;
        return hash_node(p.first) + int(p.second);
        // hash<int> hash_double;
        // return hash_double(1);
    }
};

struct pairEqual
{
    bool operator()(const pair<TreeNode*, bool>& a, const pair<TreeNode*, bool> &b) const {
        return a.first == b.first && a.second == b.second;
    }
};

 
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<pair<TreeNode*, bool>, int, pairHash, pairEqual> dp;
        return cal(root, false, dp);
    }
    
    int cal(TreeNode* root, bool fetchParent, unordered_map<pair<TreeNode*, bool>, int, pairHash, pairEqual>& dp) {
        if (root == nullptr ) return 0;
        
        if (dp.find({root, fetchParent}) != dp.end()) return dp[{root, fetchParent}];
        
        int ans = 0;
        ans = max(ans, cal(root->left, false, dp) + cal(root->right, false, dp));
        if (!fetchParent) {
            ans = max(ans, cal(root->left, true, dp) + cal(root->right, true, dp) + root->val);
        }
        
        dp[{root, fetchParent}] = ans;
        return ans;
    }
};