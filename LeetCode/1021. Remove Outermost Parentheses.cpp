// 想多了，一个单纯外面一个裸括号要特殊处理，但是事实上不用。

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(auto c : s) {
            if (c == '(') {
                if (count > 0) {
                    ans.push_back('(');
                }
                ++count;
            }
            else {
                --count;
                if (count > 0) {
                    ans.push_back(')');
                }
            }
        }
        return ans;
    }
};