// 直接按题目要求逻辑用函数往下遍历节点就能过，但是不够快
// 用队列可以消掉递归减少函数调用开销

#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    // void traversal(Node* root, int level, vector<vector<int>>& res) {
    //     if (!root) return;
    //     if (res.size() <= level) {
    //         res.push_back(vector<int>());
    //     }
    //     res[level].push_back(root->val);
    //     for (Node* n: root->children) {
    //         traversal(n, level + 1, res);
    //     }
    // }

    // vector<vector<int>> levelOrder(Node* root) {
    //     vector<vector<int>> res;
    //     traversal(root, 0, res);
    //     return res;
    // }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> nQueue;
        nQueue.push(root);
        while(!nQueue.empty()) {
            int size = nQueue.size();
            vector<int> subRes;
            while(size--) {
                Node* frontNode = nQueue.front();
                nQueue.pop();
                subRes.push_back(frontNode->val);
                for (auto& child: frontNode->children) {
                    nQueue.push(child);
                }
            }
            res.push_back(subRes);
        }
        return res;
    }
};
