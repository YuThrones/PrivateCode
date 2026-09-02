class Solution {
public:
    int scoreOfParentheses(string s) {
        int i = 0;
        int n = s.length();
        int ans = 0;
        while(i < n) {
            int end;
            ans += cal(s, i, end);
            i = end + 1;
        }
        return ans;
    }

    int cal(string& s, int start, int& end) {
        // 假定传进来的start位置都是左括号，处理完返回自己对应的右括号位置
        int n = s.length();
        if (start >= n) {
            end = start;
            return 0;
        }
        int ans = 0;
        int i = start + 1;
        while(i < n) {
            // 左括号消耗掉了，结束了
            if(s[i] == ')') {
                end = i;
                if (i == start + 1) {
                    ans = 1;
                }
                else {
                    ans *= 2;
                }
                return ans;
            }
            else {
                // 遇到了新的左括号，递归处理
                int nextEnd;
                ans += cal(s, i, nextEnd);
                i = nextEnd + 1;
            }
        }
        return ans;
    }
};