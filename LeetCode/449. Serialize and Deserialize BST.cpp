// 这道题我是按照前序遍历，用#来代表一个节点，通过有没有数字区分是否空节点的思路来序列化，然后反序列化的时候按照前序遍历的顺序来还原
// 看了下最佳答案，他的做法是利用上了我没有利用的信息，二叉搜索树的左边必定小于右边，省掉了#字符的搜索过程，memcpy可能会更快？

#include <string>
#include <stack>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string res = "#" + to_string(root->val);
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;

        TreeNode* root = nullptr;
        if (data.length() < 2) return root;
        int index = 0;
        stack<TreeNode*> st;
        bool isLeft = true;
        TreeNode* pre;
        while(index < data.length()) {
            int nextIndex = data.find('#', index + 1);
            TreeNode* temp = nullptr;
            if (nextIndex == index + 1 || index == data.length() - 1) {
                if (!st.empty()) {
                    TreeNode* top = st.top();
                    st.pop();
                    isLeft = false;
                    pre = top;
                }
                index = nextIndex;
                continue;
            }
            else if (nextIndex == -1) {
                temp = new TreeNode(stoi(data.substr(index + 1, data.length() - index - 1)));
            }
            else {
                temp = new TreeNode(stoi(data.substr(index + 1, nextIndex - index - 1)));
            }
            if (!root) {
                root = temp;
                st.push(temp);
                isLeft = true;
                pre = temp;
            }
            else {
                if (isLeft) {
                    pre->left = temp;
                }
                else {
                    pre->right = temp;
                }
                st.push(temp);
                isLeft = true;
                pre = temp;
            }
            index = nextIndex;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:

int main() {
    Codec c;
    c.deserialize("#2#1###3##");
    return 0;
}