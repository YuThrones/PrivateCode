// 遍历字符串，每个字符和它的出现次数入栈，如果跟栈顶元素相同则增加计数，否则压入新的栈，
// 当相同字符达到k之后则出栈，最后把栈中剩下的字符输出即可
// 最快解法的思路是一样的，只是不直接用stack，而是用vector来做，这样不需要逆序，会更快一点
#include<string>
#include<stack>
using namespace std;

class Info {
    public:
        char ch;
        int count;
        Info (char ch, int count):ch(ch), count(count) {
        }
};

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<Info> st = stack<Info>();
        for (char c:s) {
            if (!st.empty() && st.top().ch == c) {
                if (++st.top().count == k) {
                    st.pop();
                }
            }
            else {
                st.push(Info(c, 1));
            }
        }
        string ans;
        while(!st.empty()) {
            while (st.top().count-- > 0) {
                ans += st.top().ch;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
string removeDuplicates(string s, int k) {
    int n = s.length(); string res;
    vector<pair<char,int>> vc;
    
    vc.push_back(make_pair(s[0],1)); 
    for (int r = 1; r < n; r++) {
        if(vc.empty())  {
            vc.push_back(make_pair(s[r], 1));
             continue;
        } 
        
        auto& curr = vc.back();
        if (s[r] != curr.first)  {
            vc.push_back(make_pair(s[r], 1));
            continue;
        }
        
        curr.second = (curr.second + 1) % k;
        if (!curr.second) vc.pop_back();
    }
    
    for (auto &e: vc) {
        res.append(e.second, e.first);
    }
    return res;
}
};