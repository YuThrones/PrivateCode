// 遍历两次，第一次创建节点，第二次建立关系就行，最快解法只用一次遍历，用递归解决节点可能还没创建的问题，更加简洁
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return nullptr;
        }
        map<Node*, Node*> m = map<Node*, Node*>();
        queue<Node*> st = queue<Node*>();
        Node* cur = nullptr;
        Node* res = new Node(node->val);
        m[node] = res;
        st.push(node);
        while(!st.empty())
        {
            cur = st.front();
            st.pop();
            for (auto nei: cur->neighbors)
            {
                if (m.find(nei) == m.end())
                {
                    m[nei] = new Node(nei->val);
                    st.push(nei);
                }
            }
        }

        for (auto it = m.begin(); it != m.end(); ++it)
        {
            for (auto nei: it->first->neighbors)
            {
                it->second->neighbors.push_back(m[nei]);
            }
        }
        return res;
    }
};