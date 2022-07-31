// 这道题说难也不难，但是一开始想歪了，思路是直接找到每个数对应的最佳位置，但是这样做不出来
// 看了下论坛，发现思路有问题
// 需要用贪心的方式，先找到当前遍历过的位置最佳的选择，然后遇到新的之后通过栈撤销之前的做法

#include<vector>
#include<list>
#include<iostream>
#include<climits>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        vector<bool> use(26);
        stack<int> st;
        string res = "";

        for (auto c: s) {
            int charIndex = c - 'a';
            count[charIndex] += 1;
            use[charIndex] = false;
        }

        for (int i = 0; i < s.length(); ++i) {
            int charIndex = s[i] - 'a';
            --count[charIndex];
            if (use[charIndex]) continue;

            while(!st.empty() && s[i] < s[st.top()] && count[s[st.top()] - 'a'] > 0) {
                // 如果有一个数比栈顶的值小，并且栈顶在后面还有相同的值，那么可以出栈
                use[s[st.top()] - 'a'] = false;
                st.pop();
            }

            st.push(i);
            use[charIndex] = true;
        }
        
        while(!st.empty()) {
            res = string(1, s[st.top()]) + res;
            st.pop();
        }

        return res;
    }
};


int main() {
    Solution sol;
    cout << sol.removeDuplicateLetters("cbacdcbc") << endl;
    return 0;
}