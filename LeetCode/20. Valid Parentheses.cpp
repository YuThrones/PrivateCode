// 简单的括号对应问题，通过入栈出栈判断空栈即可
class Solution {
public:
    bool isValid(string s) {
        stack<char> st = stack<char>();
        for (char c: s) {
            if (c == '(') {
                st.push(c);
            }
            else if (c == '[') {
                st.push(c);
            }
            else if (c == '{') {
                st.push(c);
            }
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
            }
            else if (c == '}') {
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};