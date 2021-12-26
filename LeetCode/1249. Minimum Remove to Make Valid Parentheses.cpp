// 本质上是用一个栈来存储左括号，然后做匹配，还是经典问题，不过现在要存的是下标，然后把没法匹配的左括号和右括号的下标都收集起来
// 这里参考最佳答案是直接原字符串的位置设置为#，如果考虑通用情况，可能要用哈希表之类的存一下再查

#include<string>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st = stack<int>();
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (st.empty()) {
                    s[i] = '#';
                }
                else {
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution s = Solution();
    cout << s.minRemoveToMakeValid("lee(t(c)o)de)") << endl;
    cout << s.minRemoveToMakeValid("a)b(c)d") << endl;
    cout << s.minRemoveToMakeValid("))((") << endl;
    return 0;
}