// 这道题是个硬coding问题，思路不难，前序遍历一遍，然后用特殊字符代表NULL节点，把树输出为字符串即可，读的时候按照这个顺序初始化节点
// 但是这道题的边界很麻烦，必须想清楚，而且还要考虑val有负数的情况
// 看了下最快解法，人家的比我清晰很多，每次成对的设置左边和右边的节点，用宽度优先遍历来做，确实比我的更好
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (!root) {
            return res;
        }
        TreeNode* cur;
        stack<TreeNode*> st = stack<TreeNode*>();
        cur = root;
        while(cur || !st.empty()) {
            if (cur) {
                res += to_string(cur->val);
                st.push(cur);
                cur = cur->left;
                res += "L";
            }
            else {
                res += "#";
                cur = st.top();
                st.pop();
                cur = cur->right;
                res += "R";
            }
        }
        res += "#";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* head = NULL;
        TreeNode* temp;
        int num = 0;
        stack<TreeNode*> st = stack<TreeNode*>();
        int flag = 0;
        bool is_leaf = false;
        int positive_flag = 1;
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] >= '0' && data[i] <= '9') {
                num = num * 10 + data[i] - '0';
            }
            else if (data[i] == '-') {
                positive_flag = -1;
            }
            else if (data[i] == '#') {
                is_leaf = true;
            }
            else {
                if (!is_leaf) {
                    temp = new TreeNode(num * positive_flag);
                    positive_flag = 1;
                    if (head == NULL) {
                        head = temp;
                    }
                }

                if (flag == -1) {
                    if (temp) {
                        st.top()->left = temp;
                    }
                }
                else if (flag == 1) {
                    if (temp) {
                        st.top()->right = temp;
                    }
                    st.pop();
                }
                
                if (temp) {
                    st.push(temp);
                }
                num = 0;
                temp = NULL;
                is_leaf = false;
                
                if (data[i] == 'L') {
                    flag = -1;
                }
                else if (data[i] == 'R') {
                    flag = 1;
                }
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));