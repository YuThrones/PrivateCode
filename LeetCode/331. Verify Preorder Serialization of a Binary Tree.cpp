// 看了下最快解法的思路，是用递归来做的，核心思想没有变，但是比我的实现更优雅，应该在常量时间上领先
// 这道题的思路是，根据给出的前序字符串，从头开始push进栈，遇到节点为空时回溯，等到一个节点的子树遍历完把节点弹出
// 如果中途遇到了栈为空但是字符串没遍历完的情况，说明有问题
// 如果字符串遍历完了，栈不为空，说明也有问题

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int pos = 0;
        return process(preorder, pos) && pos == preorder.size();
    }
    
    bool process(const string& data, int& pos) {
        if (pos >= data.length()) {
            return false;
        }
        
        if (isdigit(data[pos])) {
            while(isdigit(data[pos])) {
                ++pos;
            }
            return process(data, ++pos) && process(data, ++pos);
        }
        
        return data[pos++] == '#';
    }
};


class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.length() == 0) {
            return true;
        }
        if (preorder == "#") {
            return true;
        }
        stringstream s(preorder);
        string str;
        getline(s, str, ',');

        if (str == "#") {
            return false;
        }

        stack<pair<string, int> > st = stack<pair<string, int> >();
        st.push(make_pair(str, -1));
        getline(s, str, ',');

        while(str != "") {
                        // cout << str << " " << st.size() << endl;
            if (st.empty()) {
                return false;
            }
            if (str == "#") {
                
                while (!st.empty() && st.top().second == 1) {
                    st.pop();
                }
                
                if (!st.empty()) {
                    st.top().second = 1;
                }
            }
            else {
                st.push(make_pair(str, -1));
            }
            str = "";
            getline(s, str, ',');
        }
        return st.empty();
    }
};