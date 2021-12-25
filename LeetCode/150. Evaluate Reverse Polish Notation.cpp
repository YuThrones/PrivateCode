// 这道题是标准的使用栈解的题目，通过栈维护最后两个需要被符号操作的数，注意出栈顺序是先第二个数后第一个数即可

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st = stack<int>();
        string s;
        int n1, n2;
        for (int i = 0; i < tokens.size(); ++i) {
            s = tokens[i];
            if (s == "+"
                || s == "-"
                || s == "*"
                || s == "/"
            ) {
                n2= st.top();
                st.pop();
                n1= st.top();
                st.pop();
                if (s == "+") {
                    st.push(n1 + n2);
                }
                else if (s == "-") {
                    st.push(n1 - n2);
                }
                else if (s == "*") {
                    st.push(n1 * n2);
                }
                else if (s == "/") {
                    st.push(n1 / n2);
                }
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};