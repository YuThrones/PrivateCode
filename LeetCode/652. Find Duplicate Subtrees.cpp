// 这道题直接拿节点比较超时了，看了下答案，还是得用特征值来做，有点忘记了

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 映射子树特征（字符串形式）到唯一ID
        unordered_map<string, int> subtreeId;
        // 记录每个ID的出现次数
        unordered_map<int, int> idCount;
        // 存储结果（重复子树的根节点）
        vector<TreeNode*> result;
        // 自增ID（确保每个唯一子树有唯一标识）
        int currentId = 0;
        
        // 后序遍历函数（用function包装以支持递归）
        function<int(TreeNode*)> postOrder = [&](TreeNode* node) -> int {
            if (!node) return -1; // 空节点用特殊ID标识
            
            // 递归获取左右子树的ID
            int leftId = postOrder(node->left);
            int rightId = postOrder(node->right);
            
            // 生成当前子树的特征字符串（val + 左子树ID + 右子树ID）
            string key = to_string(node->val) + "," + to_string(leftId) + "," + to_string(rightId);
            
            // 分配或复用ID
            int nodeId;
            if (subtreeId.find(key) != subtreeId.end()) {
                nodeId = subtreeId[key];
            } else {
                nodeId = currentId++;
                subtreeId[key] = nodeId;
            }
            
            // 统计出现次数，首次重复时加入结果
            idCount[nodeId]++;
            if (idCount[nodeId] == 2) {
                result.push_back(node);
            }
            
            return nodeId; // 返回当前子树的ID
        };
        
        postOrder(root);
        return result;
    }
};